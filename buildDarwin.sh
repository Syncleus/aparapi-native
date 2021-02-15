#!/bin/sh
echo "Aparapi Darwin (OSX) x86_64 compilation started..."

export PATH=/usr/osxcross/bin:/usr/osxcross:$PATH
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64/jre
rm -rf .libs64/linux .libs32/linux
make clean
./prepare.sh

export JAVA_HOME=/usr/src/openlogic-openjdk-8u272-b10-mac-x64/jdk1.8.0_272.jdk/Contents/Home
libtoolize
aclocal
autoconf
automake --add-missing
./configure --host=x86_64-apple-darwin
make
mkdir -p .libs64
mv .libs .libs64/linux
