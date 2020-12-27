#!/bin/bash
sudo docker run  --user root  -v $PWD:/home/root/ --workdir /home/root/   -i -t cpp-cross-compiler  /"bin/sh"
