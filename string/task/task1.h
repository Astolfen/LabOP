#ifndef INC_TASK1_H
#define INC_TASK1_H

#include "../string_.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_task1_1() {
    char s[] = "213h jk j3 kj ";

    removeNonLetters(s);

    char res[] = "213hjkj3kj";

    ASSERT_STRING(res, s);
}

void test_task1_2() {
    char s[] = "    ";

    removeNonLetters(s);

    char res[] = "";

    ASSERT_STRING(res, s);
}

void test_task1_3() {
    char s[] = "";

    removeNonLetters(s);

    char res[] = "";

    ASSERT_STRING(res, s);
}

void test_task1() {
    test_task1_1();
    test_task1_2();
    test_task1_3();
}

#endif
