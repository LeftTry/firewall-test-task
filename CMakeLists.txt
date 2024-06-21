cmake_minimum_required(VERSION 3.10)
project(firewall)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic")

# Main Executable of Firewall
add_executable(firewall
        firewall.c
        rules.c
        rules.h
)

# Random packet Generator Executable
add_executable(rand_pack_gen rand_pack_gen.c)

# Specify where to place the executable file
set_target_properties(firewall PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

set_target_properties(rand_pack_gen PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
