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

void test_task3_1() {
    char s[] = "a32bc1";

    task3(s);

    char res[] = "123abc";

    ASSERT_STRING(res, s);
}

void test_task3_2() {
    char s[] = "ab ";

    task3(s);

    char res[] = "ab ";

    ASSERT_STRING(res, s);
}

void test_task3_3() {
    char s[] = " 12 ";

    task3(s);

    char res[] = " 21 ";

    ASSERT_STRING(res, s);
}

void test_task3() {
    test_task3_1();
    test_task3_2();
    test_task3_3();
}

#endif