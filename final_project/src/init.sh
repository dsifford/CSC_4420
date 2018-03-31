#!/bin/bash

echo "${AWS_S3_ID}:${AWS_S3_SECRET}" > /etc/passwd-s3fs
chmod 600 /etc/passwd-s3fs

cd /src/s3fs-fuse || exit 1

./autogen.sh
./configure
make
make install

mkdir -p /s3mount 
s3fs dsifford-wsu /s3mount -o passwd_file=/etc/passwd-s3fs  #-o umask=0000 -o uid=0

