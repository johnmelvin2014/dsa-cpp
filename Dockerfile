# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
FROM ubuntu:latest

WORKDIR /home

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y llvm clang lldb g++ gcc gdb lldb git make cmake clangd clang-tidy clang-format python3 python3-pip tmux

# Python dev tools
RUN python3 -m pip install black flake8 mypy reorder-python-imports

WORKDIR /home/workspace
ENV HOME /home/workspace
ENV LD_LIBRARY_PATH /usr/local/lib
# COPY .bashrc /home/workspace/.bashrc
# COPY .tmux.conf /home/workspace/.tmux.conf
RUN git clone https://github.com/magicmonty/bash-git-prompt.git /home/workspace/.bash-git-prompt --depth=1

CMD /bin/bash

