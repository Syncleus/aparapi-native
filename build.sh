#!/bin/sh
make clean
./prepare.sh
libtoolize
aclocal
autoconf
automake --add-missing
./configure
make
mv .libs .libs64
./configure --build=i686-pc-linux-gnu "CFLAGS=-m32" "CXXFLAGS=-m32" "LDFLAGS=-m32"
make
mv .libs .libs32
