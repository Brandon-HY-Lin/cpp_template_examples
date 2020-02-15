cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(is_same)

add_executable(is_same is_same.cpp)

set_property(TARGET is_same PROPERTY CXX_STANDARD 17)
