#ifndef INC_TASK18_H
#define INC_TASK18_H

#include "../string_.h"

void task18(char *s1, char *s2) {
    WordDescriptor w1, w2;
    bool isW1Found, isW2Found;
    char *start1 = s1;
    char *start2 = s2;
    while ((isW1Found = getWord(start1, &w1)),
            (isW2Found = getWord(start2, &w2)),
            isW1Found || isW2Found) {

        if (isW1Found) {
            start1 = w1.end;
        } else {
            if (start1 != s1)
                *start1++ = ' ';
            start1 = copy(w2.begin, w2.end, start1);
        }

        if (isW2Found) {
            start2 = w2.end;
        } else {
            if (start2 != s2)
                *start2++ = ' ';
            start2 = copy(w1.begin, w1.end, start2);
        }
    }

    *start1 = '\0';
    *start2 = '\0';
}

//void test();

#endif