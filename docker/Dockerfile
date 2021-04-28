FROM ubuntu:20.10

RUN apt-get update && \
    apt-get -y install \
    wget \
    lsb-release \
    software-properties-common

RUN wget https://apt.llvm.org/llvm.sh && \
    chmod +x llvm.sh && \
    ./llvm.sh 12

RUN wget https://golang.org/dl/go1.15.7.linux-amd64.tar.gz && \
    tar zxvf go1.15.7.linux-amd64.tar.gz && \
    mv ./go/bin/go /usr/local/bin/go && \
    mkdir -p /usr/local/go && \
    mv /go/src/ /go/pkg/ /usr/local/go/

ENV GOPATH /.go
