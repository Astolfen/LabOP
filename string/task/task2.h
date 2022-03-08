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

void test_task2_1() {
    char s1[] = "aaa ";
    char s2[] = "aaa    d";

    removeExtraSpaces(s2);
    removeAdjacentEqualLetters(s1);

    char res1[] = "a ";
    char res2[] = "aaa d";

    ASSERT_STRING(res1, s1);
    ASSERT_STRING(res2, s2);
}

void test_task2_2() {
    char s1[] = "    ";
    char s2[] = "    ";

    removeAdjacentEqualLetters(s1);
    removeExtraSpaces(s2);

    char res1[] = " ";
    char res2[] = " ";

    ASSERT_STRING(res1, s1);
    ASSERT_STRING(res2, s2);
}

void test_task2_3() {
    char s1[] = "";
    char s2[] = "";

    removeAdjacentEqualLetters(s1);
    removeExtraSpaces(s2);

    char res1[] = "";
    char res2[] = "";

    ASSERT_STRING(res1, s1);
    ASSERT_STRING(res2, s2);
}

void test_task2() {
    test_task2_1();
    test_task2_2();
    test_task2_3();
}

#endif