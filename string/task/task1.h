#ifndef INC_TASK1_H
#define INC_TASK1_H

#include "../string_.h"

void removeNonLetters(char *s){
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

//void test();

#endif
