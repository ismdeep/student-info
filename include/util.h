//
// Created by ismdeep on 2019/11/1.
//

#ifndef UTIL_H
#define UTIL_H

char *strip(char *str) {
    int start, stop;
    start = 0;
    while ((' ' == str[start] || '\t' == str[start] || '\n' == str[start]) && str[start] != '\0') {
        ++start;
    }
    stop = start;
    while (!(' ' == str[stop] || '\t' == str[stop] || '\n' == str[stop] || '\0' == str[stop])) {
        ++stop;
    }

    char *res = (char *) malloc((stop - start + 2) * sizeof(char));

    for (int i = start; i < stop; i++) {
        res[i-start] = str[i];
    }
    res[stop - start] = '\0';
    return res;
}

#endif //UTIL_H
