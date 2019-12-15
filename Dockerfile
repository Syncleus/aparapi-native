FROM openjdk:8

RUN set -ex && apt-get update && apt-get upgrade -y && apt-get install -y build-essential ocl-icd-opencl-dev libtool autoconf autotools-dev automake maven --no-install-recommends && rm -rf /var/lib/apt/lists/*

COPY . /usr/src/app
WORKDIR /usr/src/app

RUN rm -rf /usr/src/app/.git && rm -rf /usr/src/app/java/.git

# run in shell mode with ENV expansion
CMD ./build.sh
