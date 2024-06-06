#!/bin/bash
rm CMakeCache.txt
cmake CMakeLists.txt -D  CMAKE_CXX_COMPILER=/usr/bin/arm-linux-gnueabihf-g++
make -j16
cp libfmt.a ../lib
