#!/bin/bash

rm -rf build
mkdir build
cd build

cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
cmake --build .
