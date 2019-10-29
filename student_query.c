//
// Created by ismdeep on 2019/10/30.
//

#include <stdio.h>
#include <stdlib.h>
#include <student_list.h>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        return -1;
    }

    if (strcmp(argv[1], "-id") == 0) {
        StudentList *list = student_list_fetch("student.dat");
        Student *stu = student_list_query_by_id(list, argv[2]);
        if (NULL == stu) {
            printf("Not Found: {id: \"%s\"}\n", argv[2]);
            return 0;
        }
        printf("%s\n", student_list_table_header());
        printf("%s\n", student_to_string(stu));
        return 0;
    }

    if (strcmp(argv[1], "-name") == 0) {
        StudentList *list = student_list_fetch("student.dat");
        Student *stu = student_list_query_by_name(list, argv[2]);
        if (NULL == stu) {
            printf("Not Found: {name: \"%s\"}\n", argv[2]);
            return 0;
        }
        printf("%s\n", student_list_table_header());
        printf("%s\n", student_to_string(stu));
    }

    return 0;
}