CMAKE_MINIMUM_REQUIRED(VERSION 3.4)

set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(-Wall -Wpedantic -Wextra)

enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

project(Koleje-bilety)

add_subdirectory(program)
add_subdirectory(library)

enable_testing()