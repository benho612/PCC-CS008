cmake_minimum_required(VERSION 3.24)
project(structTesting)

set(CMAKE_CXX_STANDARD 17)

add_executable(test main.cpp function.cpp function.h coordinate.h test.cpp test.h A.cpp A.h)
