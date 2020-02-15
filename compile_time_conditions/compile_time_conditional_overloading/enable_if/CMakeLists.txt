cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(enable_if)

add_executable(enable_if enable_if.cpp)

set_property(TARGET enable_if PROPERTY CXX_STANDARD 14)
