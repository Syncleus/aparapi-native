AUTOMAKE_OPTIONS = foreign
EXTRA_DIST = include src/cpp/CLHelper.h src/cpp/classtools.h src/cpp/invoke/JavaArgs.h src/cpp/invoke/OpenCLMem.h src/cpp/invoke/OpenCLKernel.h src/cpp/invoke/OpenCLJNI.h src/cpp/invoke/OpenCLArgDescriptor.h src/cpp/invoke/OpenCLProgram.h src/cpp/CLException.h src/cpp/JNIHelper.h src/cpp/Common.h src/cpp/runKernel/KernelArg.h src/cpp/runKernel/Range.h src/cpp/runKernel/ProfileInfo.h src/cpp/runKernel/AparapiBuffer.h src/cpp/runKernel/Config.h src/cpp/runKernel/Aparapi.h src/cpp/runKernel/ArrayBuffer.h src/cpp/runKernel/JNIContext.h src/cpp/runKernel/List.h
lib_LTLIBRARIES = libaparapi.la
libaparapi_la_LDFLAGS = -lOpenCL -version-info 2:0:1
libaparapi_la_CPPFLAGS = -Iinclude -I/opt/AMDAPP/SDK/include -Isrc/cpp -Isrc/cpp/runKernel -Isrc/cpp/invoke -I/usr/lib/jvm/java-8-openjdk/jre/../include -I/usr/lib/jvm/java-8-openjdk/jre/../include/linux -DCL_USE_DEPRECATED_OPENCL_1_1_APIS
libaparapi_la_SOURCES = src/cpp/runKernel/Aparapi.cpp src/cpp/runKernel/ArrayBuffer.cpp src/cpp/runKernel/AparapiBuffer.cpp src/cpp/runKernel/Config.cpp src/cpp/runKernel/JNIContext.cpp src/cpp/runKernel/KernelArg.cpp src/cpp/runKernel/ProfileInfo.cpp src/cpp/runKernel/Range.cpp src/cpp/invoke/OpenCLJNI.cpp src/cpp/invoke/OpenCLArgDescriptor.cpp src/cpp/invoke/OpenCLMem.cpp src/cpp/CLHelper.cpp src/cpp/classtools.cpp src/cpp/JNIHelper.cpp src/cpp/agent.cpp
all-local:
