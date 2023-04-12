cmake_minimum_required(VERSION 3.10)

project(AddressSanitizer)

set(SOURCE_FILES test_AddressSanitizer.cpp)
add_executable(test_AddressSanitizer ${SOURCE_FILES})
target_link_libraries(test_AddressSanitizer GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_AddressSanitizer)