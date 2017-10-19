# Aparapi jni Change Log

## 1.2.1

* createProgram in Java had the wrong signature producing a unsatisfied link exception that is now fixed.

## 1.2.0

* Fixed the context to a single device instead of all devices of a specific device type. creating a context per type breaks compilation on dopencl.
* Added jni method to write device name

## 1.1.2

* Fixed a bug whereby the kernel was compiled twice.

## 1.1.1

* Fixed some bugs where improper directory structure were referenced produced exceptions.

## 1.1.0

* Changed group id and package to com.aparapi
