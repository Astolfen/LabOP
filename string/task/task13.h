#ifndef INC_TASK13_H
#define INC_TASK13_H

#include "../string_.h"

bool haveEqualWord(char *s) {
    char *start = s;
    WordDescriptor w1, w2;
    while (getWord(start, &w1)) {
        char *cmp = w1.end;
        while (getWord(cmp, &w2)) {
            if (areWordsEqual(w1, w2))
                return true;
            cmp = w2.end;
        }
        start = w1.end;
    }
    return false;
}

//void test();

#endif