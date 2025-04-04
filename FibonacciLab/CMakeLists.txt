cmake_minimum_required(VERSION 3.24)
project(FibonacciLab)

set(CMAKE_CXX_STANDARD 17)

add_executable(FibonacciLab main.cpp iterative.cpp iterative.h Recursive.cpp Recursive.h Timer.cpp Timer.h)
