AC_INIT([libaparapi], [1.2.1], [syncleus@syncleus.com])
AC_ENABLE_SHARED(yes)
AC_ENABLE_STATIC(no)
LT_INIT
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_PROG_CXX
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
AC_CANONICAL_HOST
case $host_os in
  darwin* )
        LDFLAGS="-framework OpenCL -version-info 3:1:2"
        ;;
  mingw*)
        LDFLAGS="-no-undefined -lOpenCL -version-info 3:1:2"
        ;;
  *)
        LDFLAGS="-lOpenCL -version-info 3:1:2"
        ;;
esac
AC_SUBST([LDFLAGS])
