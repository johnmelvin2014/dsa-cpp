cmake_minimum_required(VERSION 3.10)

project(test_ArrayList)

add_subdirectory(googletest)

include_directories(${CMAKE_INSTALL_PREFIX}/include)
include_directories(${googletest/googletest/include})

set(SOURCE_FILES test_ArrayList.cpp ${CMAKE_INSTALL_PREFIX}/src/ArrayList/ArrayList.cpp)
add_executable(test_ArrayList ${SOURCE_FILES})

target_link_libraries(test_ArrayList gtest gtest_main)