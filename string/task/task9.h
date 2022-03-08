#ifndef INC_TASK9_H
#define INC_TASK9_H

#include "../string_.h"

void getString(char *s1, char *s2, char *res) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            res = copy(word1.begin, word1.end, res);
            *res++ = ' ';
            beginSearch1 = word1.end;
        }

        if (isW2Found) {
            res = copy(word2.begin, word2.end, res);
            *res++ = ' ';
            beginSearch2 = word2.end;
        }
    }
    *(--res) = '\0';
}

void test_task9_1() {
    char s1[MAX_STRING_SIZE + 1] = "1 3 5";
    char s2[MAX_STRING_SIZE + 1] = "2 4";
    char s[MAX_STRING_SIZE + 1];

    getString(s1, s2, s);

    char res[MAX_STRING_SIZE + 1] = "1 2 3 4 5";

    ASSERT_STRING(res, s);
}

void test_task9_2() {
    char s1[MAX_STRING_SIZE + 1] = "1 3 5";
    char s2[MAX_STRING_SIZE + 1] = "";
    char s[MAX_STRING_SIZE + 1];

    getString(s1, s2, s);

    char res[MAX_STRING_SIZE + 1] = "1 3 5";

    ASSERT_STRING(res, s);
}

void test_task9() {
    test_task9_1();
    test_task9_2();
}

#endif