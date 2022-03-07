#ifndef INC_TASK6_H
#define INC_TASK6_H

#include "../string_.h"

bool isSortedWords(char *s) {
    WordDescriptor lastW;
    WordDescriptor readW;
    if (!getWord(s, &lastW))
        return false;
    s = findNonSpace(lastW.end);
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

//void test();

#endif