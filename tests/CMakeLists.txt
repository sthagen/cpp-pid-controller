# add catch
if(NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/catch.hpp)
    file(DOWNLOAD https://github.com/catchorg/Catch2/releases/download/v2.13.3/catch.hpp
            ${CMAKE_CURRENT_BINARY_DIR}/catch.hpp)
endif()

set(tests
        pid_naive.cpp)

add_executable(pid_controller_test test.cpp ${tests})
target_include_directories(pid_controller_test PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(pid_controller_test PROPERTIES CXX_STANDARD 17)

enable_testing()
add_test(NAME test COMMAND pid_controller_test)
