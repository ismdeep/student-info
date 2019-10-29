cmake_minimum_required(VERSION 3.15)
project(student_add C)
project(student_list C)

set(CMAKE_C_STANDARD 99)

include_directories("./include")

add_executable(student_add student_add.c)
add_executable(student_list student_list.c)

