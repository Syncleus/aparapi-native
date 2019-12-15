![](http://aparapi.com/images/logo-text-adjacent.png)

```
git submodule init
git submodule update
./prepare.sh
libtoolize (or sometimes glibtoolize on osx)
aclocal
autoconf
automake --add-missing
./configure
make
```

Alternatively you can do the linux compile via a Docker container by issuing the following command (equivelant to the above)

```
UID=${UID} GID=${GID} docker-compose up
```

Sometimes you need to add additional include directories to specify the location of the java JNI headers for your jdk. To do this add the following to your call of the configure script:

```
./configure CXXFLAGS="-I//Library/Java/JavaVirtualMachines/jdk1.8.0_212.jdk/Contents/Home/include/ -I/Library/Java/JavaVirtualMachines/jdk1.8.0_212.jdk/Contents/Home/include/darwin"
```

Shared library in `.libs/libaparapi.dynlib` for osx and `.libs/libaparapi.so` for linux.

To prepare a 32bit version on a 64bit Linux system simply run configure as:
./configure --build=i686-pc-linux-gnu "CFLAGS=-m32" "CXXFLAGS=-m32" "LDFLAGS=-m32"

# OSX

Make sure JAVA_HOME is set properly. One way to set it is as follows

```bash
$ nano -w ~/.bash_profile

export JAVA_HOME=$(/usr/libexec/java_home)
```

# Windows

So far we have only been able to compile the windows binary using Microsoft Visual Studios 2017.

First open Git Bash and go to the project directory, make sure the project is up to date (git pull) and make sure the java submodule is updated (latest master).

Next make sure the include directory is deleted if it already exists, then run "./prepare.sh" from within Git Bash.

Open the project from MS Visual Studios, specifically the "Aparapi.sln" project file.

From the drop down at the top select x64 or Win32 depending on which version you wish to compile, then build the solution.

The DLL file will be in "Release/x64" for 64-bit or "Release" for 32-bit depending on the version you compile
