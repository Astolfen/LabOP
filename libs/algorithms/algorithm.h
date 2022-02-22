#ifndef INC_ALGORITHM_H
#define INC_ALGORITHM_H

#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

int compare_ints(const void *a, const void *b);

int cmp_long_long(const void *pa, const void *pb);

void swap_int(int *a, int *b);

void swap_float(float *a, float *b);

void insertSort(int *a, int n);

void ErrorBadAlloc(const int *a);

int getMinIndex(const int *a, int n,int index);

#endif
