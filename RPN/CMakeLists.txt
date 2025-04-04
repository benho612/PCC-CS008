cmake_minimum_required(VERSION 3.24)
project(RPN)

set(CMAKE_CXX_STANDARD 17)

add_executable(RPN main.cpp RPN.cpp RPN.h gameInterface/Application.h gameInterface/Component.h)
