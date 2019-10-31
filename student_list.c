//
// Created by ismdeep on 2019/10/29.
//

#include <stdio.h>
#include <stdlib.h>
#include <student_list.h>
#include <config.h>

int main() {
    StudentList *list = student_list_fetch(student_dat_path());
    student_list_print(list);
    return 0;
}