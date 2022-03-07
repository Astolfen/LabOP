#ifndef INC_TASK8_H
#define INC_TASK8_H

#include "../string_.h"

char *findCommas(char *begin) {
    while (*begin != '\0' && *begin != ',')
        begin++;
    return begin;
}

char *findNonCommas(char *begin) {
    while (*begin == ',')
        begin++;
    return begin;
}

bool getWordCommas(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonCommas(beginSearch);
    if (*word->begin == '\0')
        return false;

    word->end = findCommas(word->begin);
    return true;
}

bool isWordPalindrome(WordDescriptor w) {
    char *b = w.begin;
    char *e = w.end - 1;
    while (b <= e) {
        if (*b != *e)
            return false;
        b++;
        e--;
    }
    return true;
}

int getCountPalindromeWord(char *s) {
    int count = 0;
    WordDescriptor w;
    while (getWordCommas(s, &w)) {
        if (isWordPalindrome(w))
            count++;
        s = w.end;
    }
    return count;
}

//void test();

#endif