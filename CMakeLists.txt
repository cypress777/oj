cmake_minimum_required(VERSION 3.5)
project(oj)

set(CMAKE_CXX_STANDARD 11)

add_library(math_utils SHARED
        src/math_utils.hpp
        src/math_utils.cpp
        )
