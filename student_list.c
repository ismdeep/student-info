//
// Created by ismdeep on 2019/10/29.
//

#include <stdio.h>
#include <stdlib.h>
#include <student_list.h>

int main() {
    StudentList *list = student_list_fetch("student.dat");
//    Student     *student = student_create();
//    student_list_add(list, student);
//    student_list_print(list);
//    student_list_save(list, "student.dat");
    student_list_print(list);
    return 0;
}