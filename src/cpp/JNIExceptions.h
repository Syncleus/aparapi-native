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
#include <jni.h>
#include <string> 
#include <stdio.h>
#include <exception>
#include "CLHelper.h"
 
#ifndef JNI_EXCEPTIONS_H
#define JNI_EXCEPTIONS_H

class JNIException : public std::exception {

private:
   std::string _message;

public:

   ~JNIException() throw () {
   }

   JNIException(std::string message) {      
      _message = message;
   }

   JNIException(const JNIException& cle) {
      _message = cle._message;
   }

   JNIException& operator=(const JNIException& cle) {
      _message = cle._message;
      return *this;
   }

   const char* message() {
      return _message.c_str();
   }

   void printError() {
      if(_message != "") {
         fprintf(stderr, "!!!!!!! %s failed %s\n", message());
      }
   }

   const char* what() {
       return std::string("!!!!!!! " + _message + " failed\n").c_str();
   }
};


jint throwAparapiJNIRuntimeException( JNIEnv *env, std::string message );

jint throwAparapiJNIRuntimeException( JNIEnv *env, const char *message );

#endif // JNI_EXCEPTIONS_H
