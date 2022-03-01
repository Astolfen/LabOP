#ifndef INC_STRING__H
#define INC_STRING__H

#include <stdio.h>
#include <memory.h>
#include <ctype.h>

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

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

#endif
