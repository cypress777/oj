cmake_minimum_required(VERSION 3.8)
project(oj)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES PowerDigitSum.cpp utils.hpp utils.cpp LargeNumHelper.cpp LargeNumHelper.hpp)
add_executable(a.out ${SOURCE_FILES})