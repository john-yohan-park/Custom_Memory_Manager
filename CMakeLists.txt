cmake_minimum_required(VERSION 3.15)
project(pa01_memmgr_johnSMUpark)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a.out
        allocator.h
        allocatorSingleton.cpp
        allocatorSingleton.h
        FFit.cpp
        FFit.h
        functions.cpp
        functions.h
        main.cpp)
