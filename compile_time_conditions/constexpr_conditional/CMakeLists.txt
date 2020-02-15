cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(constexpr_conditional)

add_executable(constexpr_conditional constexpr_conditional.cpp)

set_property(TARGET constexpr_conditional PROPERTY CXX_STANDARD 17)
