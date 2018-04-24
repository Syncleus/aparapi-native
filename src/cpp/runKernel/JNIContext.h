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
#ifndef JNI_CONTEXT_H
#define JNI_CONTEXT_H


#include "Common.h"
#include "KernelArg.h"
#include "ProfileInfo.h"
#include "com_aparapi_internal_jni_KernelRunnerJNI.h"
#include "Config.h"

class JNIContext {
private:
   jint flags;
   jboolean valid;
public:
   jobject kernelObject;
   jobject openCLDeviceObject;
   jclass kernelClass;
   cl_device_id deviceId;
   cl_int deviceType;
   cl_context context;
   cl_command_queue commandQueue;
   cl_program program;
   cl_kernel kernel;
   jint argc;
   KernelArg** args;
   cl_event* executeEvents;
   cl_event* readEvents;
   cl_ulong profileBaseTime;
   jint* readEventArgs;
   cl_event* writeEvents;
   jint* writeEventArgs;
   jboolean firstRun;
   jint passes;
   jbyte* runKernelInBytes;
   jbyte* runKernelOutBytes;

   ProfileInfo *exec;
   FILE* profileFile;

   JNIContext(JNIEnv *jenv, jobject _kernelObject, jobject _openCLDeviceObject, jint _flags);

   static JNIContext* getJNIContext(jlong jniContextHandle){
      return((JNIContext*)jniContextHandle);
   }

   jboolean isValid(){
      return(valid);
   }

   jboolean isUsingGPU(){
      //I'm pretty sure that this is equivalend to:
      //return flags & com_aparapi_internal_jni_KernelRunnerJNI_JNI_FLAG_USE_GPU;
      return((flags&com_aparapi_internal_jni_KernelRunnerJNI_JNI_FLAG_USE_GPU)==com_aparapi_internal_jni_KernelRunnerJNI_JNI_FLAG_USE_GPU?JNI_TRUE:JNI_FALSE);
   }

   jboolean isUsingACC(){
      //I'm pretty sure that this is equivalend to:
      //return flags & com_aparapi_internal_jni_KernelRunnerJNI_JNI_FLAG_USE_ACC;
      return((flags&com_aparapi_internal_jni_KernelRunnerJNI_JNI_FLAG_USE_ACC)==com_aparapi_internal_jni_KernelRunnerJNI_JNI_FLAG_USE_ACC?JNI_TRUE:JNI_FALSE);
   }

   ~JNIContext(){
   }

   void dispose(JNIEnv *jenv, Config* config);

   /**
    * Release JNI critical pinned arrays before returning to java code
    */
   void unpinAll(JNIEnv* jenv);
};

#endif // JNI_CONTEXT_H
