/**
 * Copyright (c) 2016 - 2018 Syncleus, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "JNIContext.h"
#include "OpenCLJNI.h"
#include "List.h"

JNIContext::JNIContext(JNIEnv *jenv, jobject _kernelObject, jobject _openCLDeviceObject, jint _flags):
      kernelObject(jenv->NewGlobalRef(_kernelObject)),
      kernelClass((jclass)jenv->NewGlobalRef(jenv->GetObjectClass(_kernelObject))),
      openCLDeviceObject(jenv->NewGlobalRef(_openCLDeviceObject)),
      flags(_flags),
      profileBaseTime(0),
      passes(0),
      exec(NULL),
      deviceType(((flags&com_aparapi_internal_jni_KernelRunnerJNI_JNI_FLAG_USE_GPU)==com_aparapi_internal_jni_KernelRunnerJNI_JNI_FLAG_USE_GPU)?CL_DEVICE_TYPE_GPU:CL_DEVICE_TYPE_CPU),
      profileFile(NULL),
      valid(JNI_FALSE){
   if (flags&com_aparapi_internal_jni_KernelRunnerJNI_JNI_FLAG_USE_ACC)
      deviceType = CL_DEVICE_TYPE_ACCELERATOR;
   cl_int status = CL_SUCCESS;
   jobject platformInstance = OpenCLDevice::getPlatformInstance(jenv, openCLDeviceObject);
   cl_platform_id platformId = OpenCLPlatform::getPlatformId(jenv, platformInstance);
   deviceId = OpenCLDevice::getDeviceId(jenv, openCLDeviceObject);
   sharedMemory = OpenCLDevice::isSharedMemory(jenv, openCLDeviceObject);
   cl_device_type returnedDeviceType;
   clGetDeviceInfo(deviceId, CL_DEVICE_TYPE,  sizeof(returnedDeviceType), &returnedDeviceType, NULL);
   //fprintf(stderr, "device[%p] CL_DEVICE_TYPE = %x\n", deviceId, returnedDeviceType);

   cl_context_properties cps[3] = { CL_CONTEXT_PLATFORM, (cl_context_properties)platformId, 0 };
   cl_context_properties* cprops = (NULL == platformId) ? NULL : cps;
   context = clCreateContext( cprops, 1, &deviceId, NULL, NULL, &status);
   CLException::checkCLError(status, "clCreateContextFromType()");
   if (status == CL_SUCCESS){
      valid = JNI_TRUE;
   }
}

void JNIContext::dispose(JNIEnv *jenv, Config* config) {
   //fprintf(stderr, "dispose()\n");
   cl_int status = CL_SUCCESS;
   jenv->DeleteGlobalRef(kernelObject);
   jenv->DeleteGlobalRef(kernelClass);
   if (context != 0){
      status = clReleaseContext(context);
      //fprintf(stdout, "dispose context %0lx\n", context);
      CLException::checkCLError(status, "clReleaseContext()");
      context = (cl_context)0;
   }
   if (commandQueue != 0){
      if (config->isTrackingOpenCLResources()){
         commandQueueList.remove((cl_command_queue)commandQueue, __LINE__, __FILE__);
      }
      status = clReleaseCommandQueue((cl_command_queue)commandQueue);
      //fprintf(stdout, "dispose commandQueue %0lx\n", commandQueue);
      CLException::checkCLError(status, "clReleaseCommandQueue()");
      commandQueue = (cl_command_queue)0;
   }
   if (program != 0){
      status = clReleaseProgram((cl_program)program);
      //fprintf(stdout, "dispose program %0lx\n", program);
      CLException::checkCLError(status, "clReleaseProgram()");
      program = (cl_program)0;
   }
   if (kernel != 0){
      status = clReleaseKernel((cl_kernel)kernel);
      //fprintf(stdout, "dispose kernel %0lx\n", kernel);
      CLException::checkCLError(status, "clReleaseKernel()");
      kernel = (cl_kernel)0;
   }
   if (argc > 0){
      for (int i=0; i< argc; i++){
         KernelArg *arg = args[i];
         if (!arg->isPrimitive()){
            if (arg->isArray()) {
               if (arg->arrayBuffer != NULL){
                  arg->arrayBuffer->deleteJavaArray(jenv, arg);
                  delete arg->arrayBuffer;
                  arg->arrayBuffer = NULL;
               }
            } else if (arg->isAparapiBuffer()) {
               if (arg->aparapiBuffer != NULL){
                  arg->aparapiBuffer->deleteJavaObject(jenv, arg);
                  delete arg->aparapiBuffer;
                  arg->aparapiBuffer = NULL;
               }

            }
         }
         if (arg->name != NULL){
            free(arg->name); arg->name = NULL;
         }
         if (arg->javaArg != NULL ) {
            jenv->DeleteGlobalRef((jobject) arg->javaArg);
         }
         delete arg; arg=args[i]=NULL;
      } // for
      delete[] args; args=NULL;

      // do we need to call clReleaseEvent on any of these that are still retained....
      delete[] readEvents; readEvents = NULL;
      delete[] writeEvents; writeEvents = NULL;
      delete[] executeEvents; executeEvents = NULL;

      if (config->isProfilingEnabled()) {
         if (config->isProfilingCSVEnabled()) {
            if (profileFile != NULL && profileFile != stderr) {
               fclose(profileFile);
            }
         }
         delete[] readEventArgs; readEventArgs=0;
         delete[] writeEventArgs; writeEventArgs=0;
      }
   }
   if (config->isTrackingOpenCLResources()){
      fprintf(stderr, "after dispose{ \n");
      commandQueueList.report(stderr);
      memList.report(stderr);
      readEventList.report(stderr);
      executeEventList.report(stderr);
      writeEventList.report(stderr);
      fprintf(stderr, "}\n");
   }
}

void JNIContext::unpinAll(JNIEnv* jenv) {
   for (int i=0; i< argc; i++){
      KernelArg *arg = args[i];
      if (arg->isBackedByArray()) {
         arg->unpin(jenv);
      }
   }
}
