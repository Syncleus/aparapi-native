FROM aparapi/opencl-cross-compiler

LABEL maintainer="Jeffrey Phillips Freeman the@jeffreyfreeman.me"

RUN cd /usr/src && \
    unzip /root/openjdk/windows64/openlogic-openjdk-8u272-b10-windows-x64.zip && \
    cp -av /root/OpenCL_* /usr/src && \
    cd /usr/src/OpenCL_ARM/aarch64 && \
    ln -s libOpenCL.so.1.0.0 libOpenCL.so && \
    cd /usr/src/OpenCL_ARM/armhf && \
    ln -s libOpenCL.so.1.0.0 libOpenCL.so && \
    cp -av /root/msys2-OpenCL-headers /usr/src && \
    rm -rf /var/lib/apt/lists/*

RUN mkdir -p /usr/src/app
WORKDIR /usr/src/app

# run in shell mode with ENV expansion
CMD rm -rf .libs .libs32 .libs64 && ./buildMingW.sh && ./build.sh && ./buildArmLinux.sh
