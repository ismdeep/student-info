cmake_minimum_required(VERSION 3.10)
project(student_add    C)
project(student_list   C)
project(student_query  C)
project(student_sort   C)
project(student_remove C)
project(student_modify C)

set(CMAKE_C_STANDARD 99)

include_directories("./include")

add_executable(student_add    student_add.c   )
add_executable(student_list   student_list.c  )
add_executable(student_query  student_query.c )
add_executable(student_sort   student_sort.c  )
add_executable(student_remove student_remove.c)
add_executable(student_modify student_modify.c)
