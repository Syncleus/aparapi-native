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
#include "OpenCLMem.h"
#include "JavaArgs.h"

jobject OpenCLMem::create(JNIEnv *jenv, cl_context context, jlong argBits, jarray array){
   jsize sizeInBytes = getArraySizeInBytes(jenv, array, argBits);

   jlong memBits = 0;

   cl_int status = CL_SUCCESS;
   void *ptr = OpenCLMem::pin(jenv, array, &memBits);
   cl_mem mem = clCreateBuffer(context, bitsToOpenCLMask(argBits),  sizeInBytes, ptr, &status);
   if (status != CL_SUCCESS){
      fprintf(stderr, "buffer creation failed!\n");
   }

   jobject memInstance = OpenCLMem::create(jenv);
   OpenCLMem::setAddress(jenv, memInstance, ptr);
   OpenCLMem::setInstance(jenv, memInstance, array);
   OpenCLMem::setSizeInBytes(jenv, memInstance, sizeInBytes);
   OpenCLMem::setBits(jenv, memInstance, memBits);
   OpenCLMem::setMem(jenv, memInstance, mem);
   return(memInstance);
}

void OpenCLMem::describeBits(JNIEnv *jenv, jlong bits){
   fprintf(stderr, " %lx ", (unsigned long)bits);
   if (memisset(bits, COPY)){
      fprintf(stderr, "copy ");
   }
   if (memisset(bits, DIRTY)){
      fprintf(stderr, "dirty ");
   }
   if (memisset(bits, ENQUEUED)){
      fprintf(stderr, "enqueued ");
   }
}


cl_uint OpenCLMem::bitsToOpenCLMask(jlong argBits ){
   cl_uint mask = CL_MEM_USE_HOST_PTR;
   if (argisset(argBits, READONLY)) {
      mask |= CL_MEM_READ_ONLY;
   } else if (argisset(argBits, READWRITE)) {
      mask |= CL_MEM_READ_WRITE;
   } else if (argisset(argBits, WRITEONLY)) {
      mask |= CL_MEM_WRITE_ONLY;
   }
   return(mask);
}

jsize OpenCLMem::getPrimitiveSizeInBytes(JNIEnv *jenv, jlong argBits){
   jsize sizeInBytes = 0;
   if (argisset(argBits, DOUBLE) || argisset(argBits, LONG)){
      sizeInBytes = 8;
   } else if (argisset(argBits, FLOAT) || argisset(argBits, INT)){
      sizeInBytes = 4;
   } else if (argisset(argBits, SHORT)){
      sizeInBytes = 2;
   } else if (argisset(argBits, BYTE)){
      sizeInBytes = 1;
   }
   return(sizeInBytes);
}


void* OpenCLMem::pin(JNIEnv *jenv, jarray array, jlong *memBits){
   jboolean isCopy;
   void *ptr = jenv->GetPrimitiveArrayCritical(array, &isCopy);
   if (memBits != NULL){
      if (isCopy) {
         memadd(*memBits, COPY);
      } else {
         memreset(*memBits, COPY);
      }
   }
   return(ptr);
}


void OpenCLMem::unpin(JNIEnv *jenv, jarray array, void *ptr, jlong *memBits){
   if (argisset(*memBits, WRITEONLY)){
      jenv->ReleasePrimitiveArrayCritical(array, ptr, JNI_ABORT);
   }else{
      jenv->ReleasePrimitiveArrayCritical(array, ptr, 0);
   }
}
