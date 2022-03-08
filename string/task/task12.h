#ifndef INC_TASK12_H
#define INC_TASK12_H

#include "../string_.h"

void outputWord(WordDescriptor w) {
    char *begin = w.begin;
    while (begin < w.end) {
        printf("%c", *begin);
        begin++;
    }
}

void task12(char *s1, char *s2) {
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
    if (haveWord)
        outputWord(lastW);
}

//void test();

#endif