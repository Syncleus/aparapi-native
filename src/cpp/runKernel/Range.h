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
#ifndef RANGE_H
#define RANGE_H

#include "Common.h"
#include "JNIHelper.h"

class Range{
   public:
      static jclass rangeClazz;
      static jfieldID globalSize_0_FieldID;
      static jfieldID globalSize_1_FieldID;
      static jfieldID globalSize_2_FieldID;
      static jfieldID localSize_0_FieldID;
      static jfieldID localSize_1_FieldID;
      static jfieldID localSize_2_FieldID;
      static jfieldID dimsFieldID;
      static jfieldID localIsDerivedFieldID;
      jobject range;
      cl_int dims;
      size_t *offsets;
      size_t *globalDims;
      size_t *localDims;
      jboolean localIsDerived;
      Range(JNIEnv *jenv, jobject range);
      ~Range();
};

#endif // RANGE_H
