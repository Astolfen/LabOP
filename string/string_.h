#ifndef INC_STRING__H
#define INC_STRING__H

#include <stdbool.h>
#include <stdio.h>
#include <memory.h>
#include <ctype.h>

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

char stringBuffer_[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

BagOfWords bag_;
BagOfWords bag2_;

/// Counts the number of characters not counting the end of line string
/// \param begin pointer to the first element of the string
/// \return number of characters
size_t strlen(const char *begin);

/// Returns a pointer to the first element with the code ch in segment [begin;end)
/// \param begin pointer to the beginning of the segment
/// \param end pointer to the ending of the segment
/// \param ch element code
/// \return pointer to the element
char *find(char *begin, char *end, int ch);

/// Returns a pointer to the first non-whitespace character
/// \param begin pointer to the first element of the string
/// \return pointer to the element
char *findNonSpace(char *begin);

/// Returns a pointer to the first whitespace character
/// \param begin pointer to the first element of the string
/// \return pointer to the element
char *findSpace(char *begin);

/// Returns a pointer to the last non-whitespace character in segment (rend;rbegin]
/// \param rbegin pointer to the element of the string
/// \param rend pointer to the element of the string
/// \return pointer to the element
char *findNonSpaceReverse(char *rbegin, const char *rend);

/// Returns a pointer to the last whitespace character in segment (rend;rbegin]
/// \param rbegin pointer to the element of the string
/// \param rend pointer to the element of the string
/// \return pointer to the element
char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

char *getEndOfString(char *begin);

bool getWord(char *beginSearch, WordDescriptor *word);

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

void getBagOfWords(BagOfWords *bag, char *s);

void outputWord(WordDescriptor w);

#define ASSERT_STRING(expected, got) assert_string(expected, got, \
                                __FILE__, __FUNCTION__, __LINE__)

static void assert_string(const char *expected, const char *got,
                          const char *file, const char *func,
                          const int line) {
    if (strcmp(expected, got) != 0) {
        fprintf(stderr, "Exception file: %s\n", file);
        fprintf(stderr, "Function: %s - line: %d\n", func, line);
        fprintf(stderr, "Got:      \"%s\"\n", got);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
    } else
        fprintf(stderr, "%s - OK!\n", func);
}

#endif
