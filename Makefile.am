AUTOMAKE_OPTIONS = foreign
bin_PROGRAMS = aparapi
aparapi_LDFLAGS = -lOpenCL -shared -fPIC
aparapi_CPPFLAGS = -Iinclude -I/opt/AMDAPP/SDK/include -Isrc/cpp -Isrc/cpp/runKernel -Isrc/cpp/invoke -I/usr/lib/jvm/java-8-openjdk/jre/../include -I/usr/lib/jvm/java-8-openjdk/jre/../include/linux -DCL_USE_DEPRECATED_OPENCL_1_1_APIS -fPIC
#LDADD = /opt/AMDAPP/lib/${x86_or_x86_64}
aparapi_SOURCES = src/cpp/runKernel/Aparapi.cpp src/cpp/runKernel/ArrayBuffer.cpp src/cpp/runKernel/AparapiBuffer.cpp src/cpp/runKernel/Config.cpp src/cpp/runKernel/JNIContext.cpp src/cpp/runKernel/KernelArg.cpp src/cpp/runKernel/ProfileInfo.cpp src/cpp/runKernel/Range.cpp src/cpp/invoke/OpenCLJNI.cpp src/cpp/invoke/OpenCLArgDescriptor.cpp src/cpp/invoke/OpenCLMem.cpp src/cpp/CLHelper.cpp src/cpp/classtools.cpp src/cpp/JNIHelper.cpp src/cpp/agent.cpp