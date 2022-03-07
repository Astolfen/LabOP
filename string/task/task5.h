#ifndef INC_TASK5_H
#define INC_TASK5_H

#include "../string_.h"

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen(w1);
    size_t w2Size = strlen(w2);
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
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