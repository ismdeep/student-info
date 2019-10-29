//
// Created by ismdeep on 2019/10/28.
//



#ifndef STUDENT_H
#define STUDENT_H

#include <date.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[20];
    char name[20];
    char sex;
    Date birth_date;
    char address[100];
    char phone[20];
    char class_in[20];
} Student;


void student_init(Student *stu) {
    strcpy(stu->id, "[null]");
    strcpy(stu->name, "[null]");
    strcpy(stu->address, "[null]");
    stu->sex = '*';
    stu->birth_date.year = 1970;
    stu->birth_date.month = 1;
    stu->birth_date.day = 1;
    strcpy(stu->phone, "[null]");
    strcpy(stu->class_in, "[null]");
}


Student *student_create() {
    Student *stu = (Student *) malloc(sizeof(Student));
    student_init(stu);
    return stu;
}


char *student_to_string(const Student *student) {
    char *res = (char *) malloc(sizeof(char) * 1024);
    sprintf(res, "%8s %15s  %2d   %c %10s %9s %11s %6s",
            student->id,
            student->name,
            date_cal_age(&student->birth_date),
            student->sex,
            date_to_string(&student->birth_date),
            student->address,
            student->phone,
            student->class_in);
    return res;
}

char *student_to_raw_string(const Student *student) {
    char *res = (char *) malloc(sizeof(char) * 1024);
    sprintf(res, "%s %s %c %s %s %s %s",
            student->id,
            student->name,
            student->sex,
            date_to_string(&student->birth_date),
            student->address,
            student->phone,
            student->class_in);
    return res;
}


Student *parse_student_from_string(const char *str) {
    Student *student = (Student *) malloc(sizeof(Student));
    char birth_date_str[1024];
    sscanf(str, "%s %s %c %s %s %s %s",
           student->id,
           student->name,
           &student->sex,
           birth_date_str,
           student->address,
           student->phone,
           student->class_in
    );
    student->birth_date = *parse_date_from_string(birth_date_str);
    return student;
}

#endif //STUDENT_H
