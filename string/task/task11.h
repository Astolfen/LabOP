#ifndef INC_TASK11_H
#define INC_TASK11_H

#include "../string_.h"
#include <assert.h>

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

bool isWordHaveA(WordDescriptor w) {
    char *begin = w.begin;
    while (begin < w.end) {
        if (*begin == 'A' || *begin == 'a')
            return true;
        begin++;
    }
    return false;
}

WordBeforeFirstWordWithAReturnCode printWordBeforeFirstWordWithA(char *s) {
    WordDescriptor w, lastW;
    char *start = s;

    if (!getWord(start, &lastW))
        return EMPTY_STRING;

    if (isWordHaveA(lastW))
        return FIRST_WORD_WITH_A;

    start = lastW.end;
    while (getWord(start, &w)) {
        if (isWordHaveA(w)) {
//            outputWord(lastW);
            return WORD_FOUND;
        } else {
            lastW = w;
            start = w.end;
        }
    }
    return NOT_FOUND_A_WORD_WITH_A;
}

void test_task11_1() {
    char s[MAX_STRING_SIZE + 1] = "as da da";

    assert(printWordBeforeFirstWordWithA(s) == FIRST_WORD_WITH_A);
}

void test_task11_2() {
    char s[MAX_STRING_SIZE + 1] = "";

    assert(printWordBeforeFirstWordWithA(s) == EMPTY_STRING);
}

void test_task11_3() {
    char s[MAX_STRING_SIZE + 1] = "s gfh j hg";

    assert(printWordBeforeFirstWordWithA(s) == NOT_FOUND_A_WORD_WITH_A);
}

void test_task11_4() {
    char s[MAX_STRING_SIZE + 1] = "s gfh ja hg";

    assert(printWordBeforeFirstWordWithA(s) == WORD_FOUND);
}

void test_task11() {
    test_task11_1();
    test_task11_2();
    test_task11_3();
    test_task11_4();
}

#endif