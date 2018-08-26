cmake_minimum_required(VERSION 3.5)
project(oj)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-std=c++11 -g")

set(SOURCE_FILES PowerDigitSum.cpp LargeNumHelper.hpp LargeNumHelper.cpp utils.hpp utils.cpp)
add_executable(a.out ${SOURCE_FILES})
