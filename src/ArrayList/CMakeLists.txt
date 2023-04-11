cmake_minimum_required(VERSION 3.10)

project(ArrayList)

include_directories(${DSA_CPP_BIN_DIR}/${PROJECT_NAME})

set(SOURCE_FILES main.cpp ArrayList.cpp)
add_executable(ArrayList ${SOURCE_FILES})