cmake_minimum_required(VERSION 3.10)

project(ArrayList)

set(SOURCE_FILES test_ArrayList.cpp)
add_executable(test_ArrayList ${SOURCE_FILES})
target_link_libraries(test_ArrayList GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_ArrayList)