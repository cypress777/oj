cmake_minimum_required(VERSION 3.8)
project(oj)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES 10001thPrime.cpp utils.hpp utils.cpp)
add_executable(10001thPrime ${SOURCE_FILES})