#!/bin/sh
echo Aparapi Linux aarch64 compilation started....
rm -rf .libs64/linuxARM .libs32/linuxARM
make clean
./prepare.sh
libtoolize
aclocal
autoconf
automake --add-missing
./configure --host=aarch64-linux-gnu
make
mkdir -p .libs64
mv .libs .libs64/linuxARM
echo Aparapi Linux armhf compilation started....
make clean
./configure --host=arm-linux-gnueabihf
make
mkdir -p .libs32
mv .libs .libs32/linuxARM
