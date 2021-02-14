#!/bin/sh
echo Aparapi Linux x86_64 compilation started...
rm -rf .libs64/linux .libs32/linux
make clean
./prepare.sh
libtoolize
aclocal
autoconf
automake --add-missing
./configure 
make
mkdir -p .libs64
mv .libs .libs64/linux
echo Aparapi Linux x86 compilation started...
make clean
./configure --host=i686-pc-linux-gnu "CFLAGS=-m32" "CXXFLAGS=-m32" "LDFLAGS=-m32"
make
mkdir -p .libs32
mv .libs .libs32/linux
