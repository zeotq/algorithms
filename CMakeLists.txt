cmake_minimum_required(VERSION 3.10)
project(algorithms)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(include)
file(GLOB SOURCES "src/*.c")
file(GLOB TESTS "src/tests.c")
file(GLOB SUB_SOURCES "src/*/*.c")
add_executable(algorithms ${SOURCES})


foreach(source ${SUB_SOURCES})
    get_filename_component(executable_name ${source} NAME_WE)
    add_executable(${executable_name} ${source} ${TESTS})
endforeach()