#!/bin/bash
rm CMakeCache.txt
cmake CMakeLists.txt -D
make -j16
cp libfmt.a ../lib
