#ifndef INC_TASK19_H
#define INC_TASK19_H

#include "../string_.h"

bool task19(char *s, WordDescriptor w) {
    int a[26] = {0};
    char *start = s;
    char *end = getEndOfString(start);
    while (start < end) {
        if (isalpha(*start))
            a[*start - 'a'] -= 1;
        start++;
    }
    start = w.begin;
    end = w.end;
    while (start < end) {
        if (isalpha(*start))
            a[*start - 'a'] += 1;
        start++;
    }
    int n = 0;
    int *pa = a;
    while (n < 26) {
        if (*pa > 0)
            return false;
        n++;
        pa++;
    }
    return true;
}

//void test();

#endif