#ifndef INC_TASK6_H
#define INC_TASK6_H

#include "../string_.h"
#include <assert.h>

bool isSortedWords(char *s) {
    WordDescriptor lastW;
    WordDescriptor readW;
    if (!getWord(s, &lastW))
        return false;
    s = lastW.end;
    while (*s != '\0') {
        if (!getWord(s, &readW))
            return false;
        if (!areWordsEqual(lastW, readW)) {
            while (lastW.begin != lastW.end && readW.begin != lastW.end) {
                if (*lastW.begin > *readW.begin)
                    return false;
                lastW.begin++;
                readW.begin++;
            }
        }
        getWord(s, &lastW);
        s = findNonSpace(lastW.end);
    }
    return true;
}

void test_task6_1() {
    char s[MAX_STRING_SIZE + 1] = "a b ca cb";

    assert(isSortedWords(s));
}

void test_task6_2() {
    char s[MAX_STRING_SIZE + 1] = "sads aasd sasd";

    assert(!isSortedWords(s));
}

void test_task6() {
    test_task6_1();
    test_task6_2();
}

#endif