FROM ubuntu:trusty

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y \
        automake \
        autotools-dev \
        build-essential \
        fuse \
        g++ \
        git \
        libcurl4-openssl-dev \
        libfuse-dev \
        libssl-dev \
        libtool \
        libxml2-dev \
        make \
        mime-support \
        openssl \
        pkg-config \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /src

