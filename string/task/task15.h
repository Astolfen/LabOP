#ifndef INC_TASK15_H
#define INC_TASK15_H

#include "../string_.h"

void task15(char *s, char *res) {
    WordDescriptor w, lastW;
    getWordReverse(getEndOfString(s) - 1, s - 1, &lastW);
    char *start = s;
    char *iWrite = res;
    while (getWord(start, &w)) {
        if (!areWordsEqual(w, lastW)) {
            iWrite = copy(w.begin, w.end, iWrite);
            *iWrite++ = ' ';
        }
        start = w.end;
    }
    *(--iWrite) = '\0';
}

void test_task15_1() {
    char s1[MAX_STRING_SIZE + 1] = "1 5 3 5";
    char s[MAX_STRING_SIZE + 1];

    task15(s1, s);

    char res[MAX_STRING_SIZE + 1] = "1 3";

    ASSERT_STRING(res, s);
}

void test_task15_2() {
    char s1[MAX_STRING_SIZE + 1] = "";
    char s[MAX_STRING_SIZE + 1] = "";

    task15(s1, s);

    char res[MAX_STRING_SIZE + 1] = "";

    ASSERT_STRING(res, s);
}

void test_task15_3() {
    char s1[MAX_STRING_SIZE + 1] = "5 5 5 5 5 5 5 5";
    char s[MAX_STRING_SIZE + 1];

    task15(s1, s);

    char res[MAX_STRING_SIZE + 1] = "";

    ASSERT_STRING(res, s);
}

void test_task15() {
    test_task15_1();
    test_task15_2();
    test_task15_3();
}

#endif