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

void ErrorBadAlloc(const int *a);

int getMinIndex(const int *a, size_t n, int index);

void bubbleSort(int *a, size_t n);

void shakerSort(int *a, size_t n);

void choiceSort(int *a, size_t n);

void insertSort(int *a, size_t n);

//переделать
void combSort(int *a, size_t size);



#endif
