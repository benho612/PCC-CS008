cmake_minimum_required(VERSION 3.24)
project(cs8review)

set(CMAKE_CXX_STANDARD 17)

add_executable(cs8review main.cpp Math.cpp Math.h DivideByZeroException.cpp DivideByZeroException.h NegativeNumberException.cpp NegativeNumberException.h)
