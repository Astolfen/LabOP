#ifndef INC_TASK15_H
#define INC_TASK15_H

#include "../string_.h"

void task15(char *s) {
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
    *iWrite = '\0';
}

//void test();

#endif