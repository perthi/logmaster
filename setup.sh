#!/bin/bash
sudo cp -R productivity/3rd-party/arm/fmt-10.2.1/include/fmt /usr/include/

sudo apt-get install -y apt-utils gawk wget git git-core diffstat unzip \
     gcc-multilib build-essential chrpath socat xterm curl parted python3 \
     python3 xz-utils debianutils iputils-ping libsdl1.2-dev \
     net-tools cpio  uuid-dev sudo vim libssl-dev  libreadline-dev libxml2-dev \
     locate   libc6-armel-cross libc6-dev-armel-cross \
     binutils-arm-linux-gnueabi libncurses5-dev \
     gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf \
     autoconf libtool  python3-pip python3-protobuf

sudo apt update
sudo apt-upgrade

sudo apt-get install -y gcc-arm-none-eabi -y gcc-arm-linux-gnueabihf -y \
     gcc-aarch64-linux-gnu
sudo apt-get install --reinstall build-essential -y
sudo apt-get install g++-arm-linux-gnueabihf -y \
     git-extras -y

sudo ln -s /usr/lib/x86_64-linux-gnu/libxml2.so.2 /usr/lib/x86_64-linux-gnu/libxml2.so




