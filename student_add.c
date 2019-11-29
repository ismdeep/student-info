//
// Created by ismdeep on 2019/10/28.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <student.h>
#include <student_list.h>
#include <config.h>

int main() {
    char id[1024];
    char name[1024];
    char birth_date_str[20];
    char sex;
    char address[1024];
    char phone[1024];
    char class_in[1024];
    printf("请输入学生的学号：");
    scanf("%s", id);

    printf("请输入学生的姓名：");
    scanf("%s", name);

    printf("请输入学生的性别：");
    getchar();
    scanf("%c", &sex);

    printf("请输入学生的出生日期（例如：1999-09-23）：");
    scanf("%s", birth_date_str);

    printf("请输入学生的地址：");
    scanf("%s", address);

    printf("请输入学生的电话号码：");
    scanf("%s", phone);

    printf("请输入学生所在班级：");
    scanf("%s", class_in);

    Student student;
    student_init(&student);
    strcpy(student.id, id);
    strcpy(student.name, name);
    student.sex = sex;
    student.birth_date = *parse_date_from_string(birth_date_str);
    strcpy(student.address, address);
    strcpy(student.phone, phone);
    strcpy(student.class_in, class_in);

    StudentList *list = student_list_fetch(student_dat_path());
    student_list_add(list, &student);
    student_list_save(list, student_dat_path());
    printf("\n\nAdded: \n%s\n", student_to_content_string(&student));
    return 0;
}
