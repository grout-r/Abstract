cmake_minimum_required(VERSION 2.8.4)

project(Abstract)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

include_directories(inc)

set(SOURCE_FILES
    srcs/main.cpp
    srcs/Instructions.cpp
    srcs/IOperand.cpp
    srcs/Operand.cpp
    )

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Abstract_SOURCE_DIR}/bin)

add_executable(Abstract ${SOURCE_FILES})
