#ifndef INC_TASK16_H
#define INC_TASK16_H

#include "../string_.h"

typedef enum WordBeforeFirstWordWithReturnCode {
    NOT_FOUND_A_WORD,
    WORD_FOUND,
    EMPTY_STRING,
    FIRS_WORD
} WordBeforeFirstWordWithReturnCode;

void outputWord(WordDescriptor w) {
    char *begin = w.begin;
    while (begin < w.end) {
        printf("%c", *begin);
        begin++;
    }
}

WordBeforeFirstWordWithReturnCode task16(char *s1, char *s2) {
    WordDescriptor w1, w2, lastW;
    char *start = s1;
    if (!getWord(start, &w1))
        return EMPTY_STRING;
    while (getWord(start, &w1)) {
        char *cmp = s2;
        while (getWord(cmp, &w2)) {
            if (areWordsEqual(w1, w2)) {
                if (start == s1)
                    return FIRS_WORD;
                else {
                    outputWord(lastW);
                    return WORD_FOUND;
                }
            }
            cmp = w2.end;
        }
        start = w1.end;
        lastW = w1;
    }
    return NOT_FOUND_A_WORD;
}

//void test();

#endif