cmake_minimum_required(VERSION 3.10)

project(test_ArrayList)

add_subdirectory(googletest)

set(DSA_CPP_TEST_DIR, ${DSA_CPP_ROOT_DIR}/tests)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DSA_CPP_TEST_DIR}/bin)

include_directories(${DSA_CPP_INCLUDE_DIR})
include_directories(${googletest/googletest/include})

set(SOURCE_FILES test_ArrayList.cpp)
add_executable(test_ArrayList ${SOURCE_FILES})
set_target_properties(test_ArrayList PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${DSA_CPP_TEST_DIR}/bin)
target_link_libraries(test_ArrayList gtest gtest_main)