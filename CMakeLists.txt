cmake_minimum_required(VERSION 3.10)

project(dsa-cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(DSA_CPP_ROOT_DIR ${PROJECT_SOURCE_DIR})
set(DSA_CPP_SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(DSA_CPP_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(GOOGLETEST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/tests/googletest/googletest/include)
set(DSA_CPP_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DSA_CPP_BIN_DIR})

include_directories(${DSA_CPP_INCLUDE_DIR})

enable_testing()

add_subdirectory(src/ArrayList)
add_subdirectory(tests)