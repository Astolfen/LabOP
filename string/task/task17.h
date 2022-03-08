#ifndef INC_TASK17_H
#define INC_TASK17_H

#include "../string_.h"

void task17a(char *s) {
    WordDescriptor w, lastW;
    getWordReverse(getEndOfString(s) - 1, s - 1, &lastW);
    char *start = s;
    char *iWrite = s;
    while (getWord(start, &w)) {
        if (!areWordsEqual(w, lastW)) {
            iWrite = copy(w.begin, w.end, iWrite);
            *iWrite++ = ' ';
        }
        start = w.end;
    }
    iWrite = copy(lastW.begin, lastW.end, iWrite);
    *iWrite = '\0';
}

void test_task17_1() {
    char s[MAX_STRING_SIZE + 1] = "1 5 3 5";

    task17a(s);

    char res[MAX_STRING_SIZE + 1] = "1 3 5";

    ASSERT_STRING(res, s);
}

void test_task17_2() {
    char s[MAX_STRING_SIZE + 1] = "5 5 5 5";

    task17a(s);

    char res[MAX_STRING_SIZE + 1] = "5";

    ASSERT_STRING(res, s);
}

void test_task17_3() {
    char s[MAX_STRING_SIZE + 1] = "3";

    task17a(s);

    char res[MAX_STRING_SIZE + 1] = "3";

    ASSERT_STRING(res, s);
}

void test_task17() {
    test_task17_1();
    test_task17_2();
    test_task17_3();
}

#endif