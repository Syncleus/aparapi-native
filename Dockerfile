FROM aparapi/opencl-cross-compiler

LABEL maintainer="Jeffrey Phillips Freeman the@jeffreyfreeman.me"

# run in shell mode with ENV expansion
CMD rm -rf .libs .libs32 .libs64 && ./buildMingW.sh && ./build.sh && ./buildArmLinux.sh
