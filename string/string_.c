#include "string_.h"

size_t strlen(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;
    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;
    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin--;
    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;
    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;
    }
    return (int) *lhs - (int) *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    size_t num = endSource - beginSource;
    memcpy(beginDestination, beginSource, num);
    return beginDestination + num;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource < endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }
    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource > rendSource) {
        if (f(*rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }
        rbeginSource--;
    }
    return beginDestination;
}

char *getEndOfString(char *begin) {
    while (*begin != '\0')
        begin++;
    return begin;
}

bool getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin);
    return true;
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend);
    if (word->end == rend)
        return false;

    word->begin = findSpaceReverse(word->end, rend);
    return true;
}

char *searchWord(char *begin, char *w1) {
    begin = findNonSpace(begin);
    char *readW = w1;
    while (*begin != '\0' && *readW != '\0') {
        if (*begin == *readW) {
            begin++;
            readW++;
        } else {
            readW = w1;
            begin = findSpace(begin);
            begin = findNonSpace(begin);
        }
    }
    if (*readW == '\0')
        return begin - strlen(w1);
    else
        return begin;
}