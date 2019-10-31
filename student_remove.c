//
// Created by ismdeep on 2019/11/1.
//
#include <stdio.h>
#include <stdlib.h>
#include <student_list.h>
#include <config.h>

void help_msg() {
    printf("Usage: student_remove -id|-name ${id}\n");
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        help_msg();
        return -1;
    }

    if (strcmp(argv[1], "-id") == 0) {
        StudentList *list = student_list_fetch(student_dat_path());
        if (0 == student_list_remove_by_id(list, argv[2])) {
            printf("%s is not exists.\n", argv[2]);
        } else {
            student_list_print(list);
            student_list_save(list, student_dat_path());
        }
    }

    help_msg();

    return -1;
}