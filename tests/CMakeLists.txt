cmake_minimum_required(VERSION 3.10)

project(test_ArrayList)

include(FetchContent)
FetchContent_Declare(googletest GIT_REPOSITORY https://github.com/google/googletest.git GIT_TAG main)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(CMAKE_BUILD_TYPE Debug)

include_directories(${DSA_CPP_INCLUDE_DIR})

set(SOURCE_FILES test_ArrayList.cpp)
add_executable(test_ArrayList ${SOURCE_FILES})
target_link_libraries(test_ArrayList GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_ArrayList)