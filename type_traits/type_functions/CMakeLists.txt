cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(type_functions)

add_executable(tf type_functions.cpp)

set_property(TARGET tf PROPERTY CXX_STANDARD 14)
