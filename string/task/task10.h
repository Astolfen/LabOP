#ifndef INC_TASK10_H
#define INC_TASK10_H

#include "../string_.h"

void task10(char *s) {
    char *endStringBuffer = copy(s, getEndOfString(s), stringBuffer_);

    WordDescriptor w;
    char *start = s;
    while (getWordReverse(endStringBuffer - 1, stringBuffer_ - 1, &w)) {
        endStringBuffer = w.begin;
        start = copy(w.begin, w.end, start);
        *start++ = ' ';
    }
    *(--start) = '\0';
}

void test_task10_1() {
    char s[MAX_STRING_SIZE + 1] = "1 3 5";

    task10(s);

    char res[MAX_STRING_SIZE + 1] = "5 3 1";

    ASSERT_STRING(res, s);
}

void test_task10_2() {
    char s[MAX_STRING_SIZE + 1] = "";

    task10(s);

    char res[MAX_STRING_SIZE + 1] = "";

    ASSERT_STRING(res, s);
}

void test_task10_3() {
    char s[MAX_STRING_SIZE + 1] = "as da da";

    task10(s);

    char res[MAX_STRING_SIZE + 1] = "da da as";

    ASSERT_STRING(res, s);
}

void test_task10() {
    test_task10_1();
    test_task10_2();
    test_task10_3();
}

#endif