#ifndef INC_TASK5_H
#define INC_TASK5_H

#include "../string_.h"

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen(w1);
    size_t w2Size = strlen(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
    } else {
        copy(source, getEndOfString(source)+1, stringBuffer_);
        readPtr = stringBuffer_;
    }
    recPtr = source;

    WordDescriptor w;
    while (getWord(readPtr, &w)) {
        if (areWordsEqual(w, word1)) {
            recPtr = copy(word2.begin, word2.end, recPtr);
        } else {
            recPtr = copy(w.begin, w.end, recPtr);
        }
        *recPtr++ = ' ';
        readPtr = w.end;
    }
    *(--recPtr) = '\0';
}

void test_task5_1() {
    char s[MAX_STRING_SIZE + 1] = "a b c b";
    char w1[MAX_STRING_SIZE + 1] = "b";
    char w2[MAX_STRING_SIZE + 1] = "sd";

    replace(s, w1, w2);

    char res[MAX_STRING_SIZE + 1] = "a sd c sd";

    ASSERT_STRING(res, s);
}

void test_task5_2() {
    char s[MAX_STRING_SIZE + 1] = "sa sasa sas";
    char w1[MAX_STRING_SIZE + 1] = "sa";
    char w2[MAX_STRING_SIZE + 1] = "s";

    replace(s, w1, w2);

    char res[MAX_STRING_SIZE + 1] = "s sasa sas";

    ASSERT_STRING(res, s);
}

void test_task5() {
    test_task5_1();
    test_task5_2();
}

#endif