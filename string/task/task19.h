#ifndef INC_TASK19_H
#define INC_TASK19_H

#include "../string_.h"

bool task19(char *s, WordDescriptor w) {
    bool a[MAX_STRING_SIZE] = {false};
    char *start = s;
    char *end = getEndOfString(start);
    while (start < end) {
        if (isalpha(*start))
            a[*start - 'a'] = true;
        start++;
    }

    start = w.begin;
    end = w.end;
    while (start < end) {
        if (isalpha(*start) && a[*start - 'a'] == false)
            return false;
        start++;
    }

    return true;
}

void test_task19_1() {
    char s1[MAX_STRING_SIZE + 1] = "olheh";
    char s2[MAX_STRING_SIZE + 1] = "hello";
    WordDescriptor w;
    getWord(s2, &w);

    assert(task19(s1, w) == true);
}

void test_task19_2() {
    char s1[MAX_STRING_SIZE + 1] = "olhh";
    char s2[MAX_STRING_SIZE + 1] = "hello";
    WordDescriptor w;
    getWord(s2, &w);

    assert(task19(s1, w) == false);
}

void test_task19_3() {
    char s1[MAX_STRING_SIZE + 1] = "";
    char s2[MAX_STRING_SIZE + 1] = "hello";
    WordDescriptor w;
    getWord(s2, &w);

    assert(task19(s1, w) == false);
}

void test_task19() {
    test_task19_1();
    test_task19_2();
    test_task19_3();
}

#endif