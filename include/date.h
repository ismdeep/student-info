//
// Created by ismdeep on 2019/10/28.
//

#ifndef DATE_H
#define DATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

char *date_to_string(const Date *date) {
    char *res = (char *) malloc(sizeof(char) * 1024);
    sprintf(res, "%04d-%02d-%02d", date->year, date->month, date->day);
    return res;
}

int date_cal_age(const Date *date) {
    return 2019 - date->year;
}

Date *parse_date_from_string(const char *str) {
    Date *date = (Date *) malloc(sizeof(Date));
    sscanf(str, "%d-%d-%d", &date->year, &date->month, &date->day);
    return date;
}

#endif //DATE_H
