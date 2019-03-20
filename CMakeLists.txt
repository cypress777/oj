cmake_minimum_required(VERSION 3.5)
project(scara)

set(CMAKE_CXX_STANDARD 11)

add_library(math_utils
    src/math_utils.hpp
    src/math_utils.cpp
)
target_link_libraries(math_utils)
