#ifndef INC_TASK10_H
#define INC_TASK10_H

#include "../string_.h"

void task10(char *s) {
    char *endStringBuffer = copy(s, getEndOfString(s), stringBuffer_);

    WordDescriptor w;
    char *start = s;
    while (getWordReverse(endStringBuffer-1, stringBuffer_-1, &w)) {
        endStringBuffer = w.begin;
        start = copy(w.begin, w.end, start);
        *start++ = ' ';
    }
    *start = '\0';
}

//void test();

#endif