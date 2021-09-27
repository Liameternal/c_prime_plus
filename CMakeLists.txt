cmake_minimum_required(VERSION 3.20)
project(Single)

set(CMAKE_C_STANDARD 11)


add_executable(a.out test.c)
set_target_properties(a.out PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/")