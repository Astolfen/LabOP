#ifndef INC_TASK3_H
#define INC_TASK3_H

#include "../string_.h"

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, stringBuffer_);
    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      stringBuffer_ - 1, word.begin, isdigit);
    copyIf(stringBuffer_, endStringBuffer, recPosition, isalpha);
}

void task3(char *s) {
    char *beginSearch = s;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }
}

//void test();

#endif