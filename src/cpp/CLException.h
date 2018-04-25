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
#ifndef CL_EXCEPTION_H
#define CL_EXCEPTION_H

#include <string>
#include <stdio.h>
#include <exception>
#include "CLHelper.h"

class CLException : public std::exception {

private:
   int _status;
   std::string _message;

public:

   ~CLException() throw () {
   }

   CLException(int status, std::string message) {
      _status = status;
      _message = message;
   }

   CLException(const CLException& cle) {
      _status = cle._status;
      _message = cle._message;
   }

   CLException& operator=(const CLException& cle) {
      _status = cle._status;
      _message = cle._message;
      return *this;
   }

   int status() {
      return _status;
   }

   const char* message() {
      return _message.c_str();
   }

   void printError() {
      if(_message != "") {
         fprintf(stderr, "!!!!!!! %s failed %s\n", message(), CLHelper::errString(status()));
      }
   }

   const char* what() {
       return std::string("!!!!!!! " + _message + " failed " + CLHelper::errString(status()) + " \n").c_str();
   }

   static void checkCLError(cl_int status, std::string error) {
      if(status != CL_SUCCESS) {
         CLException(status, error).printError();
      }
   }
};


#endif // CL_EXCEPTION_H
