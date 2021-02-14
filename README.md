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

Alternatively you can do the Linux and Windows compile via a Docker container by issuing the following command (equivelant to the above)

```
UID=${UID} GID=${GID} docker-compose run --rm aparapi-native-builder
```

Sometimes you need to add additional include directories to specify the location of the java JNI headers for your jdk. To do this add the following to your call of the configure script:

```
./configure CXXFLAGS="-I//Library/Java/JavaVirtualMachines/jdk1.8.0_212.jdk/Contents/Home/include/ -I/Library/Java/JavaVirtualMachines/jdk1.8.0_212.jdk/Contents/Home/include/darwin"
```

Shared library in `.libs/libaparapi.dynlib` for osx and `.libs/libaparapi.so` for linux.

To prepare a 32bit x86 version on a 64bit x86_64 Linux system simply run configure as:
`./configure --host=i686-pc-linux-gnu` 

or, just call the script:

`./build.sh`

and it will generate both for Linux 64-bit x86_64 and Linux 32-bit x86.

- It is also possible to cross-compile for armhf and aarch64 on Linux 86_64, using the script:
`./buildARMLinux.sh` provided all the dependencies are installed and the `libOpenCL.so` file is extracted from the target
platform and placed in the correct build directory, according to `configure.ac`



# OSX

Make sure JAVA_HOME is set properly. One way to set it is as follows

```bash
$ nano -w ~/.bash_profile

export JAVA_HOME=$(/usr/libexec/java_home)
```

# Windows

- The currently tested way of cross-building the Windows binary is with MingW, there is the `buildMingW.sh` 
script which will do all the needed steps, provided MingW GCC compilers are installed in the system.

The DLLs will be at `.libs32/win` for Windows 32-bit and `.libs64/win` for Windows 64-bit.

However in order to compile Aparapi native library the `OpenCL.dll` file must be prepared for linking and 
must be placed at the proper directory depending on the architecture 32 or 64-bits. The OpenCL.dll can be 
extracted from a Windows box with the GPU drivers already installed or from the driver package itself.
Normally the file will be located, in a Windows installation, at: `%windir%\System32\OpenCL.dll`.

- To extract the interface library please use the `gendef` tool from `mingw-w64-tools` package on Ubuntu 
and probably Debian based distributions.

- The interface library is extracted for x86_64 (64 bits) with:

`gendef OpenCL.dll`

and then doing:

`x86_64-w64-mingw32-dlltool -d OpenCL.def -l libOpenCL.a`

- To extract for x86 (32 bits), do:

`gendef OpenCL.dll`

and then doing:

`x86_64-w64-mingw32-dlltool -k -d OpenCL.def -l libOpenCL.a`

- There is the alternative to compile the windows binary using Microsoft Visual Studio
2017, but it is no longer being used.

To build with Microsoft Visual Studio, you can try:

First open Git Bash and go to the project directory, make sure the project is up to date (git pull) and make sure the java submodule is updated (latest master).

Next make sure the include directory is deleted if it already exists, then run "./prepare.sh" from within Git Bash.

Open the project from MS Visual Studios, specifically the "Aparapi.sln" project file.

From the drop down at the top select x64 or Win32 depending on which version you wish to compile, then build the solution.

The DLL file will be in "Release/x64" for 64-bit or "Release" for 32-bit depending on the version you compile

# Building the aparapi-native-builder docker image

```
UID=${UID} GID=${GID} docker-compose build
UID=${UID} GID=${GID} docker-compose push
```
