#ifndef INC_TASK12_H
#define INC_TASK12_H

#include "../string_.h"

bool task12(char *s1, char *s2) {
    getBagOfWords(&bag_, s2);
    char *start = s1;
    bool haveWord = false;
    WordDescriptor w, lastW;
    while (getWord(start, &w)) {
        WordDescriptor *readBag = bag_.words;
        int count = bag_.size;
        while (count--) {
            if (areWordsEqual(w, *readBag)) {
                lastW = w;
                haveWord = true;
            }
            readBag++;
        }
        start = w.end;
    }
    return haveWord;
//    if (haveWord)
//        outputWord(lastW);
}

void test_task12_1() {
    char s1[MAX_STRING_SIZE + 1] = "";
    char s2[MAX_STRING_SIZE + 1] = "";

    assert(task12(s1, s2) == false);
}

void test_task12_2() {
    char s1[MAX_STRING_SIZE + 1] = "";
    char s2[MAX_STRING_SIZE + 1] = "sa ds";

    assert(task12(s1, s2) == false);
}

void test_task12_3() {
    char s1[MAX_STRING_SIZE + 1] = "a sd c";
    char s2[MAX_STRING_SIZE + 1] = "a 1 c";

    assert(task12(s1, s2) == true);
}

void test_task12() {
    test_task12_1();
    test_task12_2();
    test_task12_3();
}

#endif