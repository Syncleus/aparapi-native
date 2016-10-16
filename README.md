git submodule init
git submodule update
cd java
mvn clean package
cd ..
libtoolize
aclocal
autoconf
automake --add-missing
./configure
make

Shared library in .libs/libaparapi.so
