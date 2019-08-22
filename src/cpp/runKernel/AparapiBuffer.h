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
/*
   Copyright (c) 2010-2011, Advanced Micro Devices, Inc.
   All rights reserved.

   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
   following conditions are met:

   Redistributions of source code must retain the above copyright notice, this list of conditions and the following
   disclaimer.

   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
   disclaimer in the documentation and/or other materials provided with the distribution.

   Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

   If you use the software (in whole or in part), you shall adhere to all applicable U.S., European, and other export
   laws, including but not limited to the U.S. Export Administration Regulations ("EAR"), (15 C.F.R. Sections 730
   through 774), and E.U. Council Regulation (EC) No 1334/2000 of 22 June 2000.  Further, pursuant to Section 740.6 of
   the EAR, you hereby certify that, except pursuant to a license granted by the United States Department of Commerce
   Bureau of Industry and Security or as otherwise permitted pursuant to a License Exception under the U.S. Export
   Administration Regulations ("EAR"), you will not (1) export, re-export or release to a national of a country in
   Country Groups D:1, E:1 or E:2 any restricted technology, software, or source code you receive hereunder, or (2)
   export to Country Groups D:1, E:1 or E:2 the direct product of such technology or software, if such foreign produced
   direct product is subject to national security controls as identified on the Commerce Control List (currently
   found in Supplement 1 to Part 774 of EAR).  For the most current Country Group listings, or for additional
   information about the EAR or your obligations under those regulations, please refer to the U.S. Bureau of Industry
   and Security?s website at http://www.bis.doc.gov/.
   */

#ifndef APARAPIBUFFER_H
#define APARAPIBUFFER_H
#include "Common.h"
#include "ProfileInfo.h"
#include "com_aparapi_internal_jni_KernelRunnerJNI.h"

class KernelArg;

class AparapiBuffer{

private:

   static int isFloat(int type){
      return(type&com_aparapi_internal_jni_KernelRunnerJNI_ARG_FLOAT);
   }
   static int isLong(int type){
      return (type&com_aparapi_internal_jni_KernelRunnerJNI_ARG_LONG);
   }
   static int isInt(int type){
      return (type&com_aparapi_internal_jni_KernelRunnerJNI_ARG_INT);
   }
   static int isDouble(int type){
      return (type&com_aparapi_internal_jni_KernelRunnerJNI_ARG_DOUBLE);
   }
   static int isBoolean(int type){
      return (type&com_aparapi_internal_jni_KernelRunnerJNI_ARG_BOOLEAN);
   }
   static int isByte(int type){
      return (type&com_aparapi_internal_jni_KernelRunnerJNI_ARG_BYTE);
   }
   static int isShort(int type){
      return (type&com_aparapi_internal_jni_KernelRunnerJNI_ARG_SHORT);
   }

   void buildBuffer(JNIEnv* env, KernelArg* arg, void* _data, cl_uint* _dims, cl_uint _numDims, long _lengthInBytes, jobject _javaObject);

   void computeOffsets();

public:
      static int const MAX_ND_DIMS = 3;

      jobject javaObject;           // The java array that this arg is mapped to
      cl_uint numDims;              // number of dimensions of the object (array lengths for ND arrays)
      cl_uint offsets[MAX_ND_DIMS]; // offsets of the next element in ND arrays) - Aparapi currently limits ND arrays to 3 dimensions
      cl_uint lens[MAX_ND_DIMS];    // sizes of dimensions of the object (array lengths for ND arrays)
      jint lengthInBytes;           // bytes in the array or directBuf
      cl_mem mem;                   // the opencl buffer
      void *data;                   // a copy of the object itself (this is what we pass to OpenCL)
      cl_uint memMask;              // the mask used for createBuffer
      ProfileInfo read;
      ProfileInfo write;

      AparapiBuffer();
      AparapiBuffer(void* _data, cl_uint* _dims, cl_uint _numDims, long _lengthInBytes, jobject _javaObject);

      void getMinimalParams(JNIEnv *env, KernelArg* arg, cl_uint &numDims, cl_uint dims[], int &lengthInBytes) const;

      void syncMinimalParams(JNIEnv *env, KernelArg* arg);

      void deleteBuffer(KernelArg* arg);

      void flatten(JNIEnv *env, KernelArg* arg);

      void flattenBoolean2D(JNIEnv *env, KernelArg* arg);
      void flattenChar2D(JNIEnv *env, KernelArg* arg);
      void flattenByte2D(JNIEnv *env, KernelArg* arg);
      void flattenShort2D(JNIEnv *env, KernelArg* arg);
      void flattenInt2D(JNIEnv *env, KernelArg* arg);
      void flattenLong2D(JNIEnv *env, KernelArg* arg);
      void flattenFloat2D(JNIEnv *env, KernelArg* arg);
      void flattenDouble2D(JNIEnv *env, KernelArg* arg);

      void flattenBoolean3D(JNIEnv *env, KernelArg* arg);
      void flattenChar3D(JNIEnv *env, KernelArg* arg);
      void flattenByte3D(JNIEnv *env, KernelArg* arg);
      void flattenShort3D(JNIEnv *env, KernelArg* arg);
      void flattenInt3D(JNIEnv *env, KernelArg* arg);
      void flattenLong3D(JNIEnv *env, KernelArg* arg);
      void flattenFloat3D(JNIEnv *env, KernelArg* arg);
      void flattenDouble3D(JNIEnv *env, KernelArg* arg);

      void inflate(JNIEnv *env, KernelArg* arg);

      void inflateBoolean2D(JNIEnv *env, KernelArg* arg);
      void inflateChar2D(JNIEnv *env, KernelArg* arg);
      void inflateByte2D(JNIEnv *env, KernelArg* arg);
      void inflateShort2D(JNIEnv *env, KernelArg* arg);
      void inflateInt2D(JNIEnv *env, KernelArg* arg);
      void inflateLong2D(JNIEnv *env, KernelArg* arg);
      void inflateFloat2D(JNIEnv *env, KernelArg* arg);
      void inflateDouble2D(JNIEnv *env, KernelArg* arg);

      void inflateBoolean3D(JNIEnv *env, KernelArg* arg);
      void inflateChar3D(JNIEnv *env, KernelArg* arg);
      void inflateByte3D(JNIEnv *env, KernelArg* arg);
      void inflateShort3D(JNIEnv *env, KernelArg* arg);
      void inflateInt3D(JNIEnv *env, KernelArg* arg);
      void inflateLong3D(JNIEnv *env, KernelArg* arg);
      void inflateFloat3D(JNIEnv *env, KernelArg* arg);
      void inflateDouble3D(JNIEnv *env, KernelArg* arg);

      jobject getJavaObject(JNIEnv* env, KernelArg* arg) const;
      void replaceJavaObject(JNIEnv* env, KernelArg* arg, jobject newJavaObject);
      void deleteJavaObject(JNIEnv* env, KernelArg* arg);
};

#endif // ARRAYBUFFER_H
