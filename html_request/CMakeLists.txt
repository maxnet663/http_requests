cmake_minimum_required(VERSION 3.23)
project(html_requests)

set(CMAKE_CXX_STANDARD 20)

set(CPR_ENABLE_SSL OFF)
set(BUILD_CPR_TESTS_OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 871ed52d350214a034f6ef8a3b8f51c5ce1bd400) # The commit hash for 1.9.0. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

add_executable(html_request html_request.cpp)
target_link_libraries(html_request PRIVATE cpr::cpr)
