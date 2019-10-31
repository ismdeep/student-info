//
// Created by ismdeep on 2019/11/1.
//

#include <stdio.h>
#include <stdlib.h>
#include <student_list.h>
#include <config.h>
#include <util.h>

void help_msg() {
    printf("Usage: student_modify ${id}\n");
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        help_msg();
        return -1;
    }

    StudentList *list = student_list_fetch(student_dat_path());
    Student *student = student_list_query_by_id(list, argv[1]);
    if (NULL == student) {
        printf("%s is not exists.\n");
        return 0;
    }

    printf("%s\n", student_to_string(student));

    char name[1024];
    printf("请输入姓名[%s]：", student->name);
    fgets(name, 1024, stdin);
    if (strcmp("\n", name) != 0) {
        strcpy(student->name, strip(name));
    }

    char sex[1024];
    printf("请输入性别[%c]：", student->sex);
    fgets(sex, 1024, stdin);
    if (strcmp("", strip(sex)) != 0) {
        student->sex = sex[0];
    }

    char birth[1024];
    printf("请输入出生日期[%s]：", date_to_string(&student->birth_date));
    fgets(birth, 1024,stdin);
    if (strcmp("", strip(birth)) != 0) {
        student->birth_date = *parse_date_from_string(strip(birth));
    }

    char address[1024];
    printf("请输入地址[%s]：", student->address);
    fgets(address, 1024, stdin);
    if (strcmp("", strip(address)) != 0) {
        strcpy(student->address, strip(address));
    }

    char phone[1024];
    printf("请输入电话[%s]：", student->phone);
    fgets(phone, 1024, stdin);
    if (strcmp("", strip(phone)) != 0) {
        strcpy(student->phone, strip(phone));
    }

    char class_in[1024];
    printf("请输入班级[%s]：", student->class_in);
    fgets(class_in, 1024, stdin);
    if (strcmp("", strip(class_in)) != 0) {
        strcpy(student->class_in, strip(class_in));
    }

    printf("%s\n", student_to_string(student));

    student_list_save(list, student_dat_path());
    return 0;
}