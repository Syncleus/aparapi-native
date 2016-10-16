git submodule init
git submodule update
./prepare.sh
libtoolize
aclocal
autoconf
automake --add-missing
./configure
make

Shared library in .libs/libaparapi.so
