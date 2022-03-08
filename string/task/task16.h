#ifndef INC_TASK16_H
#define INC_TASK16_H

#include "../string_.h"

typedef enum WordBeforeFirstWordWithReturnCode {
    NOT_FOUND_A_WORD,
    WORD_FOUND_,
    EMPTY_STRING_,
    FIRS_WORD
} WordBeforeFirstWordWithReturnCode;

WordBeforeFirstWordWithReturnCode task16(char *s1, char *s2) {
    WordDescriptor w1, w2, lastW;
    char *start = s1;

    if (!getWord(start, &w1) || !getWord(s2, &w2))
        return EMPTY_STRING_;

    while (getWord(start, &w1)) {
        char *cmp = s2;
        while (getWord(cmp, &w2)) {
            if (areWordsEqual(w1, w2)) {
                if (start == s1)
                    return FIRS_WORD;
                else {
//                    outputWord(lastW);
                    return WORD_FOUND_;
                }
            }
            cmp = w2.end;
        }
        start = w1.end;
        lastW = w1;
    }
    return NOT_FOUND_A_WORD;
}

void test_task16_1() {
    char s1[MAX_STRING_SIZE + 1] = "as da da";
    char s2[MAX_STRING_SIZE + 1] = "as";

    assert(task16(s1, s2) == FIRS_WORD);
}

void test_task16_2() {
    char s1[MAX_STRING_SIZE + 1] = "";
    char s2[MAX_STRING_SIZE + 1] = "as";

    assert(task16(s1, s2) == EMPTY_STRING_);
}

void test_task16_3() {
    char s1[MAX_STRING_SIZE + 1] = "wa df sal";
    char s2[MAX_STRING_SIZE + 1] = "as";

    assert(task16(s1, s2) == NOT_FOUND_A_WORD);
}

void test_task16_4() {
    char s1[MAX_STRING_SIZE + 1] = "da as a";
    char s2[MAX_STRING_SIZE + 1] = "as";

    assert(task16(s1, s2) == WORD_FOUND_);
}

void test_task16() {
    test_task16_1();
    test_task16_2();
    test_task16_3();
    test_task16_4();
}

#endif