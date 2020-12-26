
FROM ubuntu:18.04
#FROM dockcross/linux-arm64

MAINTAINER Per Thomas Hille  pth@embc.no
#dockcross/linux-arm64

#USER kts

# Replace dash with bash
RUN rm /bin/sh && ln -s bash /bin/sh

RUN sed -i -e 's|disco|eoan|g' /etc/apt/sources.list
# apt update
RUN apt update --fix-missing


RUN apt-get install -y  apt-utils gawk wget git git-core diffstat unzip \
gcc-multilib build-essential chrpath socat xterm curl parted python python3 \
python3 xz-utils debianutils iputils-ping libsdl1.2-dev \
net-tools cpio  uuid-dev sudo vim libssl-dev  libreadline-dev libxml2-dev

RUN apt-get -y install locate   libc6-armel-cross libc6-dev-armel-cross \
binutils-arm-linux-gnueabi libncurses5-dev \
gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf


RUN mkdir -p  /home/root
ENV HOME /home/root


WORKDIR /home/root/

RUN apt-get -y install qemu qemu-system
 
RUN ln -s -f /usr/arm-linux-gnueabihf/lib/ld-linux-armhf.so.3 /lib/ld-linux-armhf.so.3;\
export LD_LIBRARY_PATH=/usr/local/lib/;\
LD_LIBRARY_PATH=/usr/arm-linux-gnueabihf/lib/:$LD_LIBRARY_PATH


WORKDIR /home/root/
