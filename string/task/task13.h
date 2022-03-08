#ifndef INC_TASK13_H
#define INC_TASK13_H

#include "../string_.h"

bool haveEqualWord(char *s) {
    char *start = s;
    WordDescriptor w1, w2;
    while (getWord(start, &w1)) {
        char *cmp = w1.end;
        start = w1.end;
        while (getWord(cmp, &w2)) {
            if (areWordsEqual(w1, w2))
                return true;
            cmp = w2.end;
        }
    }
    return false;
}

void test_task13_1() {
    char s[MAX_STRING_SIZE + 1] = "a sd c";

    assert(haveEqualWord(s) == false);
}

void test_task13_2() {
    char s[MAX_STRING_SIZE + 1] = "";

    assert(haveEqualWord(s) == false);
}

void test_task13_3() {
    char s[MAX_STRING_SIZE + 1] = "asd asd sad";

    assert(haveEqualWord(s) == true);
}

void test_task13() {
    test_task13_1();
    test_task13_2();
    test_task13_3();

}

#endif