cmake_minimum_required(VERSION 3.8)
project(oj)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES OptimumPolynomial.cpp utils.hpp utils.cpp)
add_executable(Optimum ${SOURCE_FILES})