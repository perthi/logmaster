#!/bin/bash

cd docker-cross
./create-image.sh
cd ..

if ! command -v docker /dev/null
then
    curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg
    sudo apt-get update
    sudo apt install apt-transport-https ca-certificates curl software-properties-common
  #  sudo apt-get install apt-transport-https ca-certificates curl gnupg lsb-release
    curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
    sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu bionic stable"
    sudo apt update
    sudo apt-get install docker-ce docker-ce-cli containerd.io
    sudo usermod -aG docker ${USER}
    su - ${USER}
    sudo chmod a+rwx  /var/run/docker.sock
    
    # echo "command docker could not be found"
   # exit
fi


#if [ $# -ne 1 ] && [ $# -ne 2 ] ;then
if [ $# -lt 1 ]; then
    echo "NUM ARGS = " $# 
    echo "Usage:" $0 "[target] where target is either x86, arm or clean"
    exit -1
fi

image_name=cpp-cross-compiler

export CURRENT_UID=$(id -u):$(id -g)


if [ $1 = "x86" ] || [ $1 = "arm" ] || [ $1 = "clean" ]; then
#    docker run --user $UID:$GID --rm  -v  ${PWD}:/home/root/ --workdir    /home/root/ $image_name "./scripts/docker/build.sh" $1
    docker run --user $CURRENT_UID --rm  -v  ${PWD}:/home/root/ --workdir    /home/root/ $image_name "./scripts/docker/build.sh" $1 $2 $3 $4
    exit $?;    
else
    echo "Unknown target " $1  "! Aborting build.."
    exit 3
fi    


exit 0




