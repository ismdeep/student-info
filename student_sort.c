//
// Created by ismdeep on 2019/10/30.
//

#include <stdio.h>
#include <student_list.h>
#include <config.h>

bool cmp_by_id(const Student *a,const Student *b) {
    if (strcmp(a->id, b->id) >= 0) {
        return true;
    }
    return false;
}

bool cmp_by_name(const Student *a, const Student *b) {
    if (strcmp(a->name, b->name) <= 0) {
        return true;
    }

    return false;
}

bool cmp_by_birth(const Student *a, const Student *b) {
    if (strcmp(date_to_string(&a->birth_date), date_to_string(&b->birth_date)) <= 0) {
        return true;
    }

    return false;
}

int main() {
    StudentList *list = student_list_fetch(student_dat_path());
    student_list_print(list);
    student_list_sort(list, cmp_by_birth);
    student_list_print(list);
    return 0;
}
