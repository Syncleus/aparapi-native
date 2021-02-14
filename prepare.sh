#!/bin/sh
mkdir include
(cd java && mvn clean org.apache.maven.plugins:maven-compiler-plugin:compile -DskipTests=true -Dmaven.javadoc.skip=true && rm -rf \?)
javah -jni -classpath ./java/target/classes -d include -force com.aparapi.internal.jni.ConfigJNI com.aparapi.internal.jni.KernelArgJNI com.aparapi.internal.jni.KernelRunnerJNI com.aparapi.internal.jni.OpenCLJNI com.aparapi.internal.jni.RangeJNI com.aparapi.Kernel com.aparapi.Range com.aparapi.Config com.aparapi.device.Device com.aparapi.device.OpenCLDevice com.aparapi.internal.kernel.KernelRunner com.aparapi.internal.opencl.OpenCLArgDescriptor com.aparapi.internal.opencl.OpenCLMem
