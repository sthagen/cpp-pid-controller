cmake_minimum_required(VERSION 3.16)
project(pid_controller VERSION 2020.12 LANGUAGES C CXX)

option(pid_controller_build_examples "whether or not to build the examples" ON)
option(pid_controller_build_tests "whether or not to build the tests" ON)

set(include_dest "include")
set(tool_dest "bin")

# subdirectories
if (pid_controller_build_tests)
    add_subdirectory(tests)
endif()
if (pid_controller_build_examples)
    macro(pid_controller_add_examples example_name)
        add_executable(${example_name} ${ARGN})
        set_target_properties(${example_name} PROPERTIES FOLDER examples)
        set_target_properties(${example_name} PROPERTIES CXX_STANDARD 17)
        target_include_directories(${example_name} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
        add_test(NAME ${example_name} COMMAND ${example_name})
    endmacro()
    add_subdirectory(examples)
endif()
