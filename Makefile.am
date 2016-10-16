AUTOMAKE_OPTIONS = foreign
bin_PROGRAMS = aparapi
aparapi_LDFLAGS = -lOpenCL -shared -fPIC
aparapi_CPPFLAGS = -Iinclude -I/opt/AMDAPP/SDK/include -Isrc/cpp -Isrc/cpp/runKernel -Isrc/cpp/invoke -I/usr/lib/jvm/java-8-openjdk/jre/../include -I/usr/lib/jvm/java-8-openjdk/jre/../include/linux -DCL_USE_DEPRECATED_OPENCL_1_1_APIS -fPIC
#LDADD = /opt/AMDAPP/lib/${x86_or_x86_64}
aparapi_SOURCES = src/cpp/runKernel/Aparapi.cpp src/cpp/runKernel/ArrayBuffer.cpp src/cpp/runKernel/AparapiBuffer.cpp src/cpp/runKernel/Config.cpp src/cpp/runKernel/JNIContext.cpp src/cpp/runKernel/KernelArg.cpp src/cpp/runKernel/ProfileInfo.cpp src/cpp/runKernel/Range.cpp src/cpp/invoke/OpenCLJNI.cpp src/cpp/invoke/OpenCLArgDescriptor.cpp src/cpp/invoke/OpenCLMem.cpp src/cpp/CLHelper.cpp src/cpp/classtools.cpp src/cpp/JNIHelper.cpp src/cpp/agent.cpp

clean: rm -rf .deps/\
	   rm Makefile\
	   rm Makefile.in\
	   rm aclocal.m4\
	   rm aparapi\
	   rm -rf autom4te.cache/\
	   rm compile\
	   rm config.log\
	   rm config.status\
	   rm configure\
	   rm depcomp\
	   rm install-sh\
	   rm missing\
	   rm -rf runKernel/\
	   rm -rf src/cpp/.deps/\
	   rm src/cpp/.dirstamp\
	   rm src/cpp/aparapi-CLHelper.o\
	   rm src/cpp/aparapi-JNIHelper.o\
	   rm src/cpp/aparapi-agent.o\
	   rm src/cpp/aparapi-classtools.o\
	   rm src/cpp/invoke/.deps/\
	   rm src/cpp/invoke/.dirstamp\
	   rm src/cpp/invoke/aparapi-OpenCLArgDescriptor.o\
	   rm src/cpp/invoke/aparapi-OpenCLJNI.o\
	   rm src/cpp/invoke/aparapi-OpenCLMem.o\
	   rm src/cpp/runKernel/.deps/\
	   rm src/cpp/runKernel/.dirstamp\
	   rm src/cpp/runKernel/aparapi-Aparapi.o\
	   rm src/cpp/runKernel/aparapi-AparapiBuffer.o\
	   rm src/cpp/runKernel/aparapi-ArrayBuffer.o\
	   rm src/cpp/runKernel/aparapi-Config.o\
	   rm src/cpp/runKernel/aparapi-JNIContext.o\
	   rm src/cpp/runKernel/aparapi-KernelArg.o\
	   rm src/cpp/runKernel/aparapi-ProfileInfo.o\
	   rm src/cpp/runKernel/aparapi-Range.o
