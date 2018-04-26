AC_INIT([libaparapi], [1.4.0], [syncleus@syncleus.com])
AC_ENABLE_SHARED(yes)
AC_ENABLE_STATIC(no)
LT_INIT
AM_INIT_AUTOMAKE([subdir-objects])
AC_PROG_CXX
AC_CONFIG_FILES([Makefile])
AC_CANONICAL_HOST
case $host_os in
  darwin* )
        AC_LDFLAGS="-framework OpenCL -version-info 5:0:4"
	AC_CPPFLAGS="-Iinclude -I/opt/AMDAPP/SDK/include -Isrc/cpp -Isrc/cpp/runKernel -Isrc/cpp/invoke -I${JAVA_HOME}/include/darwin -I${JAVA_HOME}/include -I/System/Library/Frameworks/JavaVM.framework/Versions/Current/Headers/ -DCL_USE_DEPRECATED_OPENCL_1_1_APIS"
        ;;
  mingw*)
        AC_LDFLAGS="-no-undefined -lOpenCL -version-info 5:0:4"
	AC_CPPFLAGS="-Iinclude -I/opt/AMDAPP/SDK/include -Isrc/cpp -Isrc/cpp/runKernel -Isrc/cpp/invoke -I/usr/lib/jvm/java-8-openjdk/include -I/usr/lib/jvm/java-8-openjdk/include/linux -I/usr/lib/jvm/java-8-openjdk-amd64/include -I/usr/lib/jvm/java-8-openjdk-amd64/include/linux -I/usr/lib/jvm/java-8-oracle/include -I/usr/lib/jvm/java-8-oracle/include/linux -I/System/Library/Frameworks/JavaVM.framework/Versions/Current/Headers/ -DCL_USE_DEPRECATED_OPENCL_1_1_APIS -fpermissive"
        ;;
  *)
        AC_LDFLAGS="-lOpenCL -version-info 5:0:4"
	AC_CPPFLAGS="-Iinclude -I/opt/AMDAPP/SDK/include -Isrc/cpp -Isrc/cpp/runKernel -Isrc/cpp/invoke -I/usr/lib/jvm/java-8-openjdk/include -I/usr/lib/jvm/java-8-openjdk/include/linux -I/usr/lib/jvm/java-8-openjdk-amd64/include -I/usr/lib/jvm/java-8-openjdk-amd64/include/linux -I/usr/lib/jvm/java-8-oracle/include -I/usr/lib/jvm/java-8-oracle/include/linux -I/System/Library/Frameworks/JavaVM.framework/Versions/Current/Headers/ -DCL_USE_DEPRECATED_OPENCL_1_1_APIS"
        ;;
esac
AC_SUBST(AC_LDFLAGS)
AC_SUBST(AC_CPPFLAGS)
AC_OUTPUT
