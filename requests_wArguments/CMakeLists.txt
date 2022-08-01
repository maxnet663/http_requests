cmake_minimum_required(VERSION 3.23)
project(requests_wArguments)

set(CMAKE_CXX_STANDARD 20)

set(CPR_ENABLE_SSL OFF)
set(BUILD_CPR_TESTS_OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 871ed52d350214a034f6ef8a3b8f51c5ce1bd400) 
# The commit hash for 1.9.0. Replace with the latest from: https://github.com/libcpr/cpr/releases

FetchContent_MakeAvailable(cpr)

add_executable(requests requests_warguments.cpp)
target_link_libraries(requests PRIVATE cpr::cpr)
