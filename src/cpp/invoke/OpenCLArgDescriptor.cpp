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
#include "OpenCLArgDescriptor.h"
#include "JavaArgs.h"

void OpenCLArgDescriptor::describeBits(JNIEnv *jenv, jlong bits){
   fprintf(stderr, " %lx ", (unsigned long)bits);
   if (argisset(bits, READONLY)){
      fprintf(stderr, "readonly ");
   }
   if (argisset(bits, WRITEONLY)){
      fprintf(stderr, "writeonly ");
   }
   if (argisset(bits, READWRITE)){
      fprintf(stderr, "readwrite ");
   }
   if (argisset(bits, ARRAY)){
      fprintf(stderr, "array ");
   }
   if (argisset(bits, PRIMITIVE)){
      fprintf(stderr, "primitive ");
   }
   if (argisset(bits, FLOAT)){
      fprintf(stderr, "float ");
   }
   if (argisset(bits, BYTE)){
      fprintf(stderr, "byte ");
   }
   if (argisset(bits, SHORT)){
      fprintf(stderr, "short ");
   }
   if (argisset(bits, LONG)){
      fprintf(stderr, "long ");
   }
   if (argisset(bits, DOUBLE)){
      fprintf(stderr, "double ");
   }
   if (argisset(bits, INT)){
      fprintf(stderr, "int ");
   }
   if (argisset(bits, GLOBAL)){
      fprintf(stderr, "global ");
   }
   if (argisset(bits, LOCAL)){
      fprintf(stderr, "local ");
   }
   if (argisset(bits, ISARG)){
      fprintf(stderr, "isarg ");
   }
}
