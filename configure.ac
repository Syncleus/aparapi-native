AC_INIT([libaparapi], [1.2.1], [syncleus@syncleus.com])
AC_ENABLE_SHARED(yes)
AC_ENABLE_STATIC(no)
LT_INIT
AM_INIT_AUTOMAKE([subdir-objects])
AC_PROG_CXX
AC_CONFIG_FILES([Makefile])
AC_CANONICAL_HOST
case $host_os in
  darwin* )
        AC_LDFLAGS="-framework OpenCL -version-info 3:1:2"
        ;;
  mingw*)
        AC_LDFLAGS="-no-undefined -lOpenCL -version-info 3:1:2"
        ;;
  *)
        AC_LDFLAGS="-lOpenCL -version-info 3:1:2"
        ;;
esac
AC_SUBST(AC_LDFLAGS)
AC_OUTPUT
