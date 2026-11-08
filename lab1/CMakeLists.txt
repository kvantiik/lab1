cmake_minimum_required(VERSION 4.1)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

FetchContent_MakeAvailable(googletest)


add_executable(lab1 src/main.cpp
        src/LRUCache.cpp
        src/LFUCache.cpp
        src/CacheWrapper.cpp
        tests/LRUCacheTest.cpp
        tests/LFUCacheTest.cpp
)

target_link_libraries(lab1 PRIVATE GTest::gtest)

enable_testing()
include(GoogleTest)
gtest_discover_tests(lab1)
