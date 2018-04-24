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
#ifndef JAVA_ARGS_H
#define JAVA_ARGS_H

#include "com_aparapi_internal_opencl_OpenCLArgDescriptor.h"
#include "com_aparapi_internal_opencl_OpenCLMem.h"

#define arg(token) (com_aparapi_internal_opencl_OpenCLArgDescriptor_ARG_##token##_BIT)
#define argisset(bits, token) (((bits) & arg(token)) == arg(token))
#define argset(bits, token) (bits) |= arg(token)
#define argreset(bits, token) (bits) &= ~arg(token)

#define mem(token) (com_aparapi_internal_opencl_OpenCLMem_MEM_##token##_BIT)
#define memisset(bits, token) (((bits) & mem(token)) == mem(token))
#define memadd(bits, token) (bits) |= mem(token)
#define memreset(bits, token) (bits) &= ~mem(token)

#endif //JAVA_ARGS_H
