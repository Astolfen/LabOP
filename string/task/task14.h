#ifndef INC_TASK14_H
#define INC_TASK14_H

#include "../string_.h"
#include "../task/task13.h"
#include <stdlib.h>

int compare_char(const void *a, const void *b) {
    char arg1 = *(const char *) a;
    char arg2 = *(const char *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

bool task14(char *s) {
    char *endBuf = copy(s, getEndOfString(s), stringBuffer_);
    *endBuf = '\0';
    char *start = stringBuffer_;
    WordDescriptor w;
    while (getWord(start, &w)) {
        qsort(w.begin, w.end - w.begin, sizeof(char), compare_char);
        start = w.end;
    }
    return haveEqualWord(stringBuffer_);
}

//void test();

#endif