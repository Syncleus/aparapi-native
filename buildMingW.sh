#!/bin/sh
echo Aparapi MingW Win64 compilation started....
rm -rf .libs64/win .libs32/win
make clean
./prepare.sh
libtoolize
aclocal
autoconf
automake --add-missing
./configure --host=x86_64-w64-mingw32
make
mkdir -p .libs64
mv .libs .libs64/win
cp /usr/lib/gcc/x86_64-w64-mingw32/9.3-win32/libstdc++-6.dll .libs64/win
cp /usr/lib/gcc/x86_64-w64-mingw32/9.3-win32/libgcc_s_seh-1.dll .libs64/win
echo Aparapi MingW Win32 compilation started....
make clean
./configure --host=i686-w64-mingw32
make
mkdir -p .libs32
mv .libs .libs32/win
cp /usr/lib/gcc/i686-w64-mingw32/9.3-win32/libstdc++-6.dll .libs32/win
cp /usr/lib/gcc/i686-w64-mingw32/9.3-win32/libgcc_s_sjlj-1.dll .libs32/win
