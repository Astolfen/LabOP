#ifndef INC_TASK18_H
#define INC_TASK18_H

#include "../string_.h"

void task18(char *s1, char *s2) {
    WordDescriptor w1, w2;
    bool isW1Found, isW2Found;
    char *start1 = s1;
    char *start2 = s2;
    while ((isW1Found = getWord(start1, &w1)),
            (isW2Found = getWord(start2, &w2)),
            isW1Found || isW2Found) {

        if (isW1Found) {
            start1 = w1.end;
        } else {
            if (start1 != s1)
                *start1++ = ' ';
            start1 = copy(w2.begin, w2.end, start1);
        }

        if (isW2Found) {
            start2 = w2.end;
        } else {
            if (start2 != s2)
                *start2++ = ' ';
            start2 = copy(w1.begin, w1.end, start2);
        }
    }

    *start1 = '\0';
    *start2 = '\0';
}

void test_task18_1() {
    char s1[MAX_STRING_SIZE + 1] = "3";
    char s2[MAX_STRING_SIZE + 1] = "3";

    task18(s1, s2);

    char res1[MAX_STRING_SIZE + 1] = "3";
    char res2[MAX_STRING_SIZE + 1] = "3";

    ASSERT_STRING(res1, s1);
    ASSERT_STRING(res2, s2);
}

void test_task18_2() {
    char s1[MAX_STRING_SIZE + 1] = "3 2";
    char s2[MAX_STRING_SIZE + 1] = "1";

    task18(s1, s2);

    char res1[MAX_STRING_SIZE + 1] = "3 2";
    char res2[MAX_STRING_SIZE + 1] = "1 2";

    ASSERT_STRING(res1, s1);
    ASSERT_STRING(res2, s2);
}

void test_task18_3() {
    char s1[MAX_STRING_SIZE + 1] = "";
    char s2[MAX_STRING_SIZE + 1] = "1";

    task18(s1, s2);

    char res1[MAX_STRING_SIZE + 1] = "1";
    char res2[MAX_STRING_SIZE + 1] = "1";

    ASSERT_STRING(res1, s1);
    ASSERT_STRING(res2, s2);
}

void test_task18() {
    test_task18_1();
    test_task18_2();
    test_task18_3();
}

#endif