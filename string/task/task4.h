#ifndef INC_TASK4_H
#define INC_TASK4_H

#include "../string_.h"

void task4(char *s) {
    char *recPtr = _stringBuffer;
    char *endStringBuffer = copy(s, getEndOfString(s), _stringBuffer);
    char *begin = s;
    while (recPtr != endStringBuffer) {
        if (isalpha(*recPtr)) {
            *begin = *recPtr;
            begin++;
            recPtr++;
        }
        if (isdigit(*recPtr)) {
            int count = *recPtr - '0';
            while (count > 0) {
                *begin = ' ';
                begin++;
                count--;
            }
            recPtr++;
        }
    }
    *begin = '\0';
}

//void test();

#endif