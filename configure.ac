AC_INIT([libaparapi], [1.4.2], [syncleus@syncleus.com])
AC_ENABLE_SHARED(yes)
AC_ENABLE_STATIC(no)
AC_CONFIG_MACRO_DIRS([m4])
LT_INIT
AM_INIT_AUTOMAKE([subdir-objects])
AC_PROG_CXX
AC_CONFIG_FILES([Makefile])
AC_CANONICAL_HOST

HOST_CPU_BITS=""
case $host_cpu in
  x86_64|aarch64*|mips64*|ppc64*|sparc64 )
        HOST_CPU_BITS="64"
        ;;
  i?86|arm*|mips*|ppc*|sparc )
        HOST_CPU_BITS="32"
        ;;
esac
AC_SUBST(HOST_CPU_BITS)

HOST_ARCH=""
case $host_cpu in
  aarch64* )
       HOST_ARCH="aarch64"
       ;;
  arm* ) 
       HOST_ARCH="armhf"
       ;;
  * )
       HOST_ARCH="other"
       ;;
esac
AC_SUBST(HOST_ARCH)

case $host_os in
  darwin* )
        AC_LDFLAGS="-framework OpenCL -version-info 5:3:4"
	AC_CPPFLAGS="-Iinclude -I/opt/AMDAPP/SDK/include -Isrc/cpp -Isrc/cpp/runKernel -Isrc/cpp/invoke -I${JAVA_HOME}/include/darwin -I${JAVA_HOME}/include -I/System/Library/Frameworks/JavaVM.framework/Versions/Current/Headers/ -DCL_USE_DEPRECATED_OPENCL_1_1_APIS"
        ;;
  mingw*)
        case $HOST_CPU_BITS in
        32 )
            EXTRA_LDFLAGS="-Wl,--kill-at"
            EXTRA_CPPFLAGS=""
            ;;
        64 )
            EXTRA_LDFLAGS=""
            EXTRA_CPPFLAGS=""
            ;;
        esac
        AC_LDFLAGS="-no-undefined -lOpenCL -version-info 5:3:4 -L/usr/src/OpenCL_DLL/win$HOST_CPU_BITS $EXTRA_LDFLAGS"
	AC_CPPFLAGS="-Iinclude -Isrc/cpp -Isrc/cpp/runKernel -Isrc/cpp/invoke -I/usr/src/openlogic-openjdk-8u272-b10-windows-64/include -I/usr/src/openlogic-openjdk-8u272-b10-windows-64/include/win32 -DCL_USE_DEPRECATED_OPENCL_1_1_APIS -fpermissive -I/usr/src/msys2-OpenCL-headers/mingw64/include $EXTRA_CPPFLAGS"
        ;;
  *)
        LIB_PATH=""
        case $HOST_ARCH in
        aarch64 | armhf)
             LIB_PATH="-L/usr/src/OpenCL_ARM/$HOST_ARCH"
             ;;
        esac
        AC_LDFLAGS="-lOpenCL -version-info 5:3:4 $LIB_PATH"
	AC_CPPFLAGS="-Iinclude -Isrc/cpp -Isrc/cpp/runKernel -Isrc/cpp/invoke -I/usr/lib/jvm/java-8-openjdk-amd64/include/ -I/usr/lib/jvm/java-8-openjdk-amd64/include/linux -I/System/Library/Frameworks/JavaVM.framework/Versions/Current/Headers/ -DCL_USE_DEPRECATED_OPENCL_1_1_APIS"
        ;;
esac
AC_SUBST(AC_LDFLAGS)
AC_SUBST(AC_CPPFLAGS)
AC_OUTPUT
