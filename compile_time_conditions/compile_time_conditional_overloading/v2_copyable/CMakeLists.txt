cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(copyable)

add_executable(copyable copyable.cpp)

set_property(TARGET copyable PROPERTY CXX_STANDARD 17)
