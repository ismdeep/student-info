//
// Created by ismdeep on 2019/11/1.
//

#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *student_dat_path()
{
    char *str = (char *) malloc(1024 * sizeof(char));
    strcpy(str, "student.dat");
    return str;
}

#endif //CONFIG_H
