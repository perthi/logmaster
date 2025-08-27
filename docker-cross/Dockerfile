#FROM ubuntu:22.04
FROM ubuntu:24.10
MAINTAINER Per Thomas Hille  pth@embc.no


# Replace dash with bash
RUN rm /bin/sh && ln -s bash /bin/sh

RUN sed -i -e 's|disco|eoan|g' /etc/apt/sources.list
# apt update
RUN apt update --fix-missing


RUN apt-get install -y  apt-utils gawk wget git git-core diffstat unzip
RUN apt-get install -y  gcc-multilib build-essential chrpath socat xterm curl parted python3
RUN apt-get install -y  python3 xz-utils debianutils iputils-ping libsdl1.2-dev
RUN apt-get install -y  net-tools cpio  uuid-dev sudo vim libssl-dev  libreadline-dev libxml2-dev
RUN apt-get install -y  locate   libc6-armel-cross libc6-dev-armel-cross
RUN apt-get install -y binutils-arm-linux-gnueabi libncurses5-dev \
gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf \
autoconf libtool  python3-pip python3-protobuf
# RUN apt-get install -y qemu qemu-system
# setuptools \
# qemu qemu-system

#RUN export UID=$GUID

WORKDIR /tmp
RUN wget https://github.com/protocolbuffers/protobuf/releases/download/v3.13.0/protobuf-all-3.13.0.tar.gz
RUN tar -xzf protobuf-all-3.13.0.tar.gz 
WORKDIR /tmp/protobuf-3.13.0
RUN ./configure --prefix=/usr
RUN make -j8
RUN make install
RUN ldconfig
WORKDIR /tmp/protobuf-3.13.0/python
#RUN python3 setup.py build

RUN mkdir -p  /home/root
ENV HOME /home/root

WORKDIR /home/root/

RUN ln -s -f /usr/arm-linux-gnueabihf/lib/ld-linux-armhf.so.3 /lib/ld-linux-armhf.so.3;\
export LD_LIBRARY_PATH=/usr/local/lib/;\
LD_LIBRARY_PATH=/usr/arm-linux-gnueabihf/lib/:$LD_LIBRARY_PATH

FROM gcc:13.3.0

#RUN apt-get install -y gcc-arm-none-eabi
RUN apt update
RUN apt install gcc-arm-none-eabi -y
RUN apt install gcc-arm-linux-gnueabihf -y
RUN apt install gcc-aarch64-linux-gnu -y
RUN apt-get update
RUN apt-get install --reinstall build-essential -y
RUN apt-get install g++-arm-linux-gnueabihf -y
RUN apt-get install git-extras -y


WORKDIR /root
RUN mkdir temp
WORKDIR /root/temp
RUN curl -OL https://github.com/Kitware/CMake/releases/download/v3.27.4/cmake-3.27.4.tar.gz
RUN tar -xzvf cmake-3.27.4.tar.gz
WORKDIR /root/temp/cmake-3.27.4
RUN ./bootstrap -- -DCMAKE_BUILD_TYPE:STRING=Release
RUN make -j16
RUN make install




WORKDIR /root
RUN rm -rf temp


WORKDIR /home/root/
RUN git config --global --add safe.directory /home/root 
COPY files/fmt-10.2.1.tar.gz .
RUN gunzip   fmt-10.2.1.tar.gz 
RUN tar -xvf fmt-10.2.1.tar
RUN cd  fmt-10.2.1 && cmake CMakeLists.txt && make -j16 && make install && cd  ..


