#ifndef INC_TASK11_H
#define INC_TASK11_H

#include "../string_.h"

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

void outputWord(WordDescriptor w) {
    char *begin = w.begin;
    while (begin < w.end) {
        printf("%c", *begin);
        begin++;
    }
}

void printWordBeforeFirstWordWithA(char *s) {
    WordDescriptor w, lastW;
    char *start = s;
    if (getWord(start, &lastW) && !isWordHaveA(lastW)) {
        start = lastW.end;
        bool haveA = false;
        while (getWord(start, &w) && !haveA) {
            if (isWordHaveA(w)) {
                haveA = true;
                outputWord(lastW);
            } else {
                lastW = w;
                start = w.end;
            }
        }
    }
}

//void test();

#endif