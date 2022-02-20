#include "algorithm.h"

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int swap_int(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insertSort(int *a, int n) {
    for (size_t i = 1; i < n; ++i) {
        size_t j = i;
        while (a[j] < a[j - 1] && j > 0) {
            swap_int(&a[j], &a[j - 1]);
            j--;
        }
    }
}

void ErrorBadAlloc(const int *a) {
    if (a == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
}

int getMinIndex(const int *a, int n){
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[min] > a[i])
            min = i;
    return min;

}