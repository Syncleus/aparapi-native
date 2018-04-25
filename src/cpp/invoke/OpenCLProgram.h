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

#ifndef OPEN_CL_PROGRAM_H
#define OPEN_CL_PROGRAM_H

#include "JNIHelper.h"
#include "ProfileInfo.h"

class OpenCLProgram{
   public:
      static jobject create(JNIEnv *jenv, cl_program program, cl_command_queue queue,
                            cl_context context, jobject deviceInstance, jstring source,
                            jstring log) {
         return(JNIHelper::createInstance(jenv, OpenCLProgramClass,
                     ArgsVoidReturn( LongArg LongArg LongArg
                         OpenCLDeviceClassArg StringClassArg) ,
                     (jlong)program, (jlong)queue, (jlong)context, deviceInstance, source));
      }

      static cl_context getContext(JNIEnv *jenv, jobject programInstance){
         return((cl_context) JNIHelper::getInstanceField<jlong>(jenv, programInstance, "contextId"));
      }
      static cl_program getProgram(JNIEnv *jenv, jobject programInstance){
         return((cl_program) JNIHelper::getInstanceField<jlong>(jenv, programInstance, "programId"));
      }
      static ProfileInfo** getProfileInfo(JNIEnv *jenv, jobject programInstance){
         return((ProfileInfo**) JNIHelper::getInstanceField<jlong>(jenv, programInstance, "profileInfo"));
      }
      static void setProfileInfo(JNIEnv *jenv, jobject programInstance, ProfileInfo **profileInfo){
         JNIHelper::setInstanceField<jlong>(jenv, programInstance, "profileInfo", (jlong)profileInfo);
      }
      static cl_command_queue getCommandQueue(JNIEnv *jenv, jobject programInstance){
         return((cl_command_queue)JNIHelper::getInstanceField<jlong>(jenv, programInstance, "queueId"));
      }
};


#endif //OPEN_CL_PROGRAM_H
