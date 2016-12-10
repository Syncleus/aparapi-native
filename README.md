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

To prepare a 32bit version on a 64bit system simply run configure as:
./configure --build=i686-pc-linux-gnu "CFLAGS=-m32" "CXXFLAGS=-m32" "LDFLAGS=-m32"
