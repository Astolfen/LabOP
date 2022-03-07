#ifndef INC_TASK2_H
#define INC_TASK2_H

#include "../string_.h"

void removeExtraSpaces(char *s) {
    char *begin = findSpace(s);
    char *iWrite = begin;
    while (*begin != '\0') {
        if (isspace(*begin)) {
            *iWrite = *begin;
            iWrite++;
            begin = findNonSpace(begin);
        } else {
            *iWrite = *begin;
            iWrite++;
            begin++;
        }
    }
    *iWrite = '\0';
}

void removeAdjacentEqualLetters(char *s) {
    char *begin = s + 1;
    while (*begin != '\0' && *(begin - 1) != *begin)
        begin++;
    char *iWrite = begin;
    char dupLetters = *begin;    //duplicate Letters
    while (*begin != '\0') {
        if (*begin != dupLetters) {
            *iWrite = *begin;
            iWrite++;
            dupLetters = *begin;
        }
        begin++;
    }
    *iWrite = '\0';
}

//void test();

#endif