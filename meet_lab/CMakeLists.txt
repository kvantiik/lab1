cmake_minimum_required(VERSION 4.1)
project(oop1)

set(CMAKE_CXX_STANDARD 20)

add_executable(oop1
        main.cpp
        WordFrequency.cpp
)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
