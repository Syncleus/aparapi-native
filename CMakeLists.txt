cmake_minimum_required(VERSION 3.6)
project(aparapi_native)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    src/cpp/invoke/JavaArgs.h
    src/cpp/invoke/OpenCLArgDescriptor.cpp
    src/cpp/invoke/OpenCLArgDescriptor.h
    src/cpp/invoke/OpenCLJNI.cpp
    src/cpp/invoke/OpenCLJNI.h
    src/cpp/invoke/OpenCLKernel.h
    src/cpp/invoke/OpenCLMem.cpp
    src/cpp/invoke/OpenCLMem.h
    src/cpp/invoke/OpenCLProgram.h
    src/cpp/runKernel/Aparapi.cpp
    src/cpp/runKernel/Aparapi.h
    src/cpp/runKernel/AparapiBuffer.cpp
    src/cpp/runKernel/AparapiBuffer.h
    src/cpp/runKernel/ArrayBuffer.cpp
    src/cpp/runKernel/ArrayBuffer.h
    src/cpp/runKernel/Config.cpp
    src/cpp/runKernel/Config.h
    src/cpp/runKernel/JNIContext.cpp
    src/cpp/runKernel/JNIContext.h
    src/cpp/runKernel/KernelArg.cpp
    src/cpp/runKernel/KernelArg.h
    src/cpp/runKernel/List.h
    src/cpp/runKernel/ProfileInfo.cpp
    src/cpp/runKernel/ProfileInfo.h
    src/cpp/runKernel/Range.cpp
    src/cpp/runKernel/Range.h
    src/cpp/agent.cpp
    src/cpp/classtools.cpp
    src/cpp/classtools.h
    src/cpp/classtoolstest.cpp
    src/cpp/CLException.h
    src/cpp/CLHelper.cpp
    src/cpp/CLHelper.h
    src/cpp/cltest.cpp
    src/cpp/Common.h
    src/cpp/JNIHelper.cpp
    src/cpp/JNIHelper.h)

include_directories(include)

add_executable(aparapi_native ${SOURCE_FILES})