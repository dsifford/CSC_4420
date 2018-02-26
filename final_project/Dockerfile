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

RUN git clone https://github.com/s3fs-fuse/s3fs-fuse \
    && cd s3fs-fuse \
    && ./autogen.sh \
    && ./configure --prefix=/usr --with-openssl \
    && make \
    && make install
