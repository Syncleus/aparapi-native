#!/bin/sh
make clean
./prepare.sh
libtoolize
aclocal
autoconf
automake --add-missing
./configure
make
