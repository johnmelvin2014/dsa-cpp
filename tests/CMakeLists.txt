cmake_minimum_required(VERSION 3.10)

project(tests)

set(DSA_CPP_TESTING_DIR ${DSA_CPP_ROOT_DIR}/tests)
set(DSA_CPP_TESTING_BIN_DIR ${DSA_CPP_TESTING_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DSA_CPP_TESTING_BIN_DIR})

include(FetchContent)
FetchContent_Declare(googletest GIT_REPOSITORY https://github.com/google/googletest.git GIT_TAG main)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(CMAKE_BUILD_TYPE Debug)
add_compile_options(-fsanitize=leak,address,undefined -fno-omit-frame-pointer -fno-common -O1)
link_libraries(-fsanitize=leak,address,undefined)

include_directories(${DSA_CPP_INCLUDE_DIR})

add_subdirectory(ArrayList)