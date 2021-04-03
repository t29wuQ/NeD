FROM ubuntu:20.10

RUN apt-get update && \
    apt-get -y install \
    wget \
    lsb-release \
    software-properties-common

RUN wget https://apt.llvm.org/llvm.sh && \
    chmod +x llvm.sh && \
    ./llvm.sh 11

