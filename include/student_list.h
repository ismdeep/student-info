//
// Created by ismdeep on 2019/10/29.
//

#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include <stdbool.h>
#include <student.h>

typedef struct {
    size_t size;
    size_t cnt;
    Student *list;
} StudentList;

StudentList *student_list_fetch(char *path) {
    StudentList *list = (StudentList *) malloc(sizeof(StudentList));
    list->size = 1024;
    list->cnt = 0;
    list->list = (Student *) malloc(sizeof(Student) * 1024);

    FILE *fp = fopen(path, "r");
    if (!fp) {
        printf("%s not found!\n", path);
        return list;
    }

    char str[1024];
    while (fgets(str, 1024, fp)) {
        Student *stu = parse_student_from_string(str);
        list->list[list->cnt] = *stu;
        ++list->cnt;
    }

    return list;
}

void student_list_add(StudentList *list, const Student *student) {
    list->list[list->cnt] = *student;
    ++list->cnt;
}

void student_list_save(const StudentList *list, const char *path) {
    FILE *fp = fopen(path, "w");
    if (!fp) {
        printf("Error, Can NOT create %s\n", path);
        return;
    }
    for (int i = 0; i < list->cnt; ++i) {
        fprintf(fp, "%s\n", student_to_raw_string(&list->list[i]));
    }
    fclose(fp);
}

char *student_list_table_header() {
    char *str = (char *) malloc(sizeof(char) * 1024);
    strcpy(str, "      ID            Name Age Sex      Birth   Address       Phone  Class");
    return str;
}

void student_list_print(const StudentList *list) {
    printf("Size: %d    Cnt: %d\n", list->size, list->cnt);
    printf("%s\n", student_list_table_header());
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < list->cnt; ++i) {
        printf("%s\n", student_to_string(&list->list[i]));
    }
}

Student *student_list_query_by_id(const StudentList *list, char *id_str) {
    for (int i = 0; i < list->cnt; ++i) {
        if (strcmp(list->list[i].id, id_str) == 0) {
            return &list->list[i];
        }
    }
    return NULL;
}

Student *student_list_query_by_name(const StudentList *list, char *name_str) {
    for (int i = 0; i < list->cnt; ++i) {
        if (strcmp(list->list[i].name, name_str) == 0) {
            return &list->list[i];
        }
    }
    return NULL;
}

typedef bool (*fun_t)(const Student*, const Student*);

void *student_list_sort(StudentList *list, fun_t cmp) {
    for (int left = 0; left <= list->cnt - 2; left++) {
        int m = left;
        for (int i = left + 1; i < list->cnt; i++) {
            if (!cmp(&list->list[m], &list->list[i])) {
                m = i;
            }
        }
        Student tmp;
        tmp = list->list[left];
        list->list[left] = list->list[m];
        list->list[m] = tmp;
    }
}

#endif //STUDENT_LIST_H
