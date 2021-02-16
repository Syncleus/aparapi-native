# Aparapi jni Changelog

## 1.4.3

* Improve Aparapi native to enforce Kernel and Device max work group size limitations and provide query functions for clGetKernelWorkGroupInfo(...)
* Updated Docker and build configurations to use new image for cross-building Aparapi native for multiple platforms
* Allow Aparapi native to run on untested OpenCL Platform versions, just issuing a WARNING message

## 1.4.2

* Fixed Potential JVM crash when using multi-dimensional arrays (> 1D)

## 1.4.1

* Fixed exception handling when calling Java method OpenCLDevice.configure() to not hide exceptions

## 1.4.0

* Fixed local arrays handling 1D and ND, to cope with arrays resizing across kernel executions
* Significant speed-up on discrete GPUs with dedicated memory - OpenCLDevice.setSharedMemory(false)
* Now supports efficient execution on discrete GPU and other devices with dedicated memory
* Support for OpenCLDevice configurator/configure API

## 1.3.1

* Fixed JVM crash with multi-dimensional arrays in Local memory (2D and 3D local arrays are now supported)

## 1.3.0

* createProgram in Java had the wrong signature producing a unsatisfied link exception that is now fixed.
* The same scripts can now compile for Linux and OSX and potentially even windows.
* Now supports OpenCL 2.1.

## 1.2.0

* Fixed the context to a single device instead of all devices of a specific device type. creating a context per type breaks compilation on dopencl.
* Added jni method to write device name

## 1.1.2

* Fixed a bug whereby the kernel was compiled twice.

## 1.1.1

* Fixed some bugs where improper directory structure were referenced produced exceptions.

## 1.1.0

* Changed group id and package to com.aparapi
