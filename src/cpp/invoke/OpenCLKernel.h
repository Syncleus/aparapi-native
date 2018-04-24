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
#ifndef OPEN_CL_KERNEL_H
#define OPEN_CL_KERNEL_H

#include "Common.h"
#include "JNIHelper.h"

class OpenCLKernel{
   public:

      static jobject create(JNIEnv *jenv, cl_kernel kernel, jobject programInstance, jstring name, jobjectArray args){
         return(JNIHelper::createInstance(jenv, OpenCLKernelClass,
                     ArgsVoidReturn( LongArg OpenCLProgramClassArg StringClassArg ArrayArg(OpenCLArgDescriptorClass)),
                     (jlong)kernel, programInstance, name, args));
      }

      static cl_kernel getKernel(JNIEnv *jenv, jobject kernelInstance){
          cl_kernel k = (cl_kernel) JNIHelper::getInstanceField<jlong>(jenv, kernelInstance, "kernelId");
         return((cl_kernel) JNIHelper::getInstanceField<jlong>(jenv, kernelInstance, "kernelId"));
      }

      static jobject getProgramInstance(JNIEnv *jenv, jobject kernelInstance){
         return(JNIHelper::getInstanceField<jobject>(jenv, kernelInstance, "program", OpenCLProgramClassArg));
      }

      static jobjectArray getArgsArray(JNIEnv *jenv, jobject kernelInstance){
         return(reinterpret_cast<jobjectArray>
                     (JNIHelper::getInstanceField<jobject>(jenv, kernelInstance, "args",
                        ArrayArg(OpenCLArgDescriptorClass) )));
      }
};

#endif //OPEN_CL_KERNEL_H
