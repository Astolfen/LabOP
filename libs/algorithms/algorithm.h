#ifndef INC_ALGORITHM_H
#define INC_ALGORITHM_H

#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>

int compare_ints(const void *a, const void *b);

int swap_int(int *a, int *b);

void insertSort(int *a, int n);

void ErrorBadAlloc(const int *a);

int abs_int(int a) {
    return a > 0 ? a : -a;
}

#endif
