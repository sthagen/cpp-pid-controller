cmake_minimum_required(VERSION 3.16)
project(pid_controller VERSION 2020.12 LANGUAGES C CXX)

set(include_dest "include")
set(tool_dest "bin")

add_executable(pid_example
               examples/pid.cpp)

set_target_properties(pid_example PROPERTIES CXX_STANDARD 17)
