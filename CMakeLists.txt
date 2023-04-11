cmake_minimum_required(VERSION 3.10)

project(dsa-cpp)

set (CXX /usr/bin/clang++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -std=c++2a")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(DSA_CPP_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(GOOGLETEST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/tests/googletest/googletest/include)

set(DSA_CPP_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DSA_CPP_INSTALL_BIN_DIR})
#set(DIVISIBLE_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

#set(DIVISION_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/division)

include_directories(${DSA_CPP_INCLUDE_DIR})
#include_directories(${DIVISION_HEADERS_DIR})

enable_testing()

add_subdirectory(src/ArrayList)
add_subdirectory(tests)