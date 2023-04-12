# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
FROM ubuntu:20.04

ENV TZ America/New_York

RUN apt-get update -y && apt-get upgrade -y

# tzdata issue https://serverfault.com/questions/949991/how-to-install-tzdata-on-a-ubuntu-docker-image
RUN DEBIAN_FRONTEND=noninteractive TZ=America/New_York apt-get -y install tzdata
RUN apt-get -y install llvm clang g++ gcc gdb lldb git make cmake clangd clang-tidy clang-format python3 python3-pip

# # Python dev tools
RUN python3 -m pip install black flake8 mypy reorder-python-imports

ENV HOME /home
ENV LD_LIBRARY_PATH /usr/local/lib
RUN git clone https://github.com/magicmonty/bash-git-prompt.git /home/workspace/.bash-git-prompt --depth=1

CMD /bin/bash

