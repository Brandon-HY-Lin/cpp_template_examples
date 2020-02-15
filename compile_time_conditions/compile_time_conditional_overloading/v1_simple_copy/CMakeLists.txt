cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(simple_copy)

add_executable(simple_copy simple_copy.cpp)

set_property(TARGET simple_copy PROPERTY CXX_STANDARD 14)
