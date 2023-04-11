#!/bin/bash

shopt -s extglob

cd build
rm -rf -- !(.gitignore)

cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
cmake --build .
