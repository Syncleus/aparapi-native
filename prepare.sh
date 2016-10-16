#!/bin/sh
mkdir include
(cd java && mvn clean package)
javah -jni -classpath ./java/target/classes -d include -force com.syncleus.aparapi.internal.jni.ConfigJNI com.syncleus.aparapi.internal.jni.KernelArgJNI com.syncleus.aparapi.internal.jni.KernelRunnerJNI com.syncleus.aparapi.internal.jni.OpenCLJNI com.syncleus.aparapi.internal.jni.RangeJNI com.syncleus.aparapi.Kernel com.syncleus.aparapi.Range com.syncleus.aparapi.Config com.syncleus.aparapi.device.Device com.syncleus.aparapi.device.OpenCLDevice com.syncleus.aparapi.internal.kernel.KernelRunner com.syncleus.aparapi.internal.opencl.OpenCLArgDescriptor com.syncleus.aparapi.internal.opencl.OpenCLMem
