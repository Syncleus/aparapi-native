AC_INIT([libaparapi], [1.0.0], [jeffrey.freeman@syncleus.com])
AC_ENABLE_SHARED(yes)
AC_ENABLE_STATIC(no)
LT_INIT
AM_INIT_AUTOMAKE([subdir-objects])
AC_PROG_CXX
AC_CONFIG_FILES([Makefile])
AC_CONFIG_COMMANDS([mkdir include], [cd java && mvn clean package], [javah -jni -classpath ./java/target/classes -d include -force com.amd.aparapi.internal.jni.ConfigJNI com.amd.aparapi.internal.jni.KernelArgJNI com.amd.aparapi.internal.jni.KernelRunnerJNI com.amd.aparapi.internal.jni.OpenCLJNI com.amd.aparapi.internal.jni.RangeJNI com.amd.aparapi.Kernel com.amd.aparapi.Range com.amd.aparapi.Config com.amd.aparapi.device.Device com.amd.aparapi.device.OpenCLDevice com.amd.aparapi.internal.kernel.KernelRunner com.amd.aparapi.internal.opencl.OpenCLArgDescriptor com.amd.aparapi.internal.opencl.OpenCLMem])
AC_OUTPUT