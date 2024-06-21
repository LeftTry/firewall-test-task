cmake_minimum_required(VERSION 3.10)
project(firewall)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic")

add_executable(firewall
        firewall.c
        rules.c
        rules.h
)

# Specify where to place the executable file
set_target_properties(firewall PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
