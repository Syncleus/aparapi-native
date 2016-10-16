AC_INIT([libaparapi], [1.0.0], [jeffrey.freeman@syncleus.com])
AC_ENABLE_SHARED(yes)
AC_ENABLE_STATIC(no)
LT_INIT
AM_INIT_AUTOMAKE([subdir-objects])
AC_PROG_CXX
AC_CONFIG_FILES([Makefile])
AC_CONFIG_COMMANDS([mkdir include], [cd java && mvn clean package], [javah -jni -classpath ./java/target/classes -d include -force com.syncleus.aparapi.internal.jni.ConfigJNI com.syncleus.aparapi.internal.jni.KernelArgJNI com.syncleus.aparapi.internal.jni.KernelRunnerJNI com.syncleus.aparapi.internal.jni.OpenCLJNI com.syncleus.aparapi.internal.jni.RangeJNI com.syncleus.aparapi.Kernel com.syncleus.aparapi.Range com.syncleus.aparapi.Config com.syncleus.aparapi.device.Device com.syncleus.aparapi.device.OpenCLDevice com.syncleus.aparapi.internal.kernel.KernelRunner com.syncleus.aparapi.internal.opencl.OpenCLArgDescriptor com.syncleus.aparapi.internal.opencl.OpenCLMem])
AC_OUTPUT