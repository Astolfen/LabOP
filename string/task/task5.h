#ifndef INC_TASK5_H
#define INC_TASK5_H

#include "../string_.h"

char *searchWord(char *begin, char *w1) {
    char *start = begin;
    begin = findNonSpace(start);
    char *readW = w1;
    while (*start != '\0' && *readW != '\0') {
        if (*start == *readW) {
            start++;
            readW++;
        } else {
            readW = w1;
            start = findSpace(start);
            start = findNonSpace(start);
        }
    }
    if (*readW == '\0')
        return start - strlen(w1);
    else
        return start;
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen(w1);
    size_t w2Size = strlen(w2);
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
    } else {
        copy(source, getEndOfString(source), stringBuffer_);
        readPtr = stringBuffer_;
    }
    recPtr = source;

    char *read = searchWord(readPtr, w1);
    recPtr += read - readPtr;
    readPtr = read;
    while (*readPtr != '\0') {
        readPtr += strlen(w1);
        recPtr = copy(word2.begin, word2.end, recPtr);
        read = searchWord(readPtr, w1);
        if (*read == '\0') {
            recPtr = copy(readPtr, getEndOfString(readPtr), recPtr);
        } else {
            recPtr = copy(readPtr, read, recPtr);
        }
        readPtr = read;
    }
    *recPtr = '\0';
}

//void test();

#endif