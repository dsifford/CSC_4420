#!/bin/bash

set -e

if [ "$#" -ne 1 ]; then
    echo "Invalid arguments"
    echo "usage: "
    echo "./init.sh bucket-name [mount-directory]"
    exit 1
fi

declare BUCKET_NAME="$1"
declare MOUNT_DIR="${2:-/s3mount}"

echo "${AWS_S3_ID}:${AWS_S3_SECRET}" > /etc/passwd-s3fs
chmod 600 /etc/passwd-s3fs

cd /src/s3fs-fuse || exit 1

./autogen.sh
./configure
make
make install

mkdir -p "$MOUNT_DIR"
s3fs "$BUCKET_NAME" "$MOUNT_DIR" -o passwd_file=/etc/passwd-s3fs 

