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
    copy(s, getEndOfString(s) + 1, stringBuffer_);
    char *start = stringBuffer_;
    WordDescriptor w;
    while (getWord(start, &w)) {
        qsort(w.begin, w.end - w.begin, sizeof(char), compare_char);
        start = w.end;
    }
    return haveEqualWord(stringBuffer_);
}

void test_task14_1() {
    char s[MAX_STRING_SIZE + 1] = "asd sad";

    assert(task14(s) == true);
}

void test_task14_2() {
    char s[MAX_STRING_SIZE + 1] = "";

    assert(task14(s) == false);
}

void test_task14_3() {
    char s[MAX_STRING_SIZE + 1] = "a b c";

    assert(task14(s) == false);
}

void test_task14() {
    test_task14_1();
    test_task14_2();
    test_task14_3();
}

#endif