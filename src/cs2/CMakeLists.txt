cmake_minimum_required(VERSION 3.16)
project(c C)

set(CMAKE_C_STANDARD 99)

add_executable(endian endian.c)
add_executable(hex hexadecimal.c)
add_executable(address address.c)
add_executable(cs2.5 2.5.c)
add_executable(cs2.7 2.7.c)
add_executable(cs2.8 2.8.c)