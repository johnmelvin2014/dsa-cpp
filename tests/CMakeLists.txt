cmake_minimum_required(VERSION 3.10)

project(test_ArrayList)

enable_testing()

add_subdirectory(googletest)

set(DSA_CPP_TEST_DIR, ${DSA_CPP_ROOT_DIR}/tests)

include_directories(${DSA_CPP_INCLUDE_DIR})
include_directories(${googletest/googletest/include})

set(SOURCE_FILES test_ArrayList.cpp)
add_executable(test_ArrayList ${SOURCE_FILES})
target_link_libraries(test_ArrayList gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(test_ArrayList)