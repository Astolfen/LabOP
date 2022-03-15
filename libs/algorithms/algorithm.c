#include "algorithm.h"

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

void swap_int(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swap_float(float *a, float *b) {
    float t = *a;
    *a = *b;
    *b = t;
}

void ErrorBadAlloc(const int *a) {
    if (a == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
}

int getMinIndex(const int *a, size_t n, int index) {
    int min = index;
    for (int i = index; i < n; i++)
        if (a[min] > a[i])
            min = i;
    return min;
}

//sorts

void bubbleSort(int *a, size_t n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (a[j] > a[j + 1])
                swap_int(&a[j], &a[j + 1]);
        }
    }
}

void shakerSort(int *a, size_t n) {
    int l = 0;
    int r = (int) n - 1;
    while (l < r) {
        for (int j = l; j < r; j++)
            if (a[j] > a[j + 1])
                swap_int(&a[j], &a[j + 1]);
        r--;
        for (int j = r; j > l; j--)
            if (a[j] < a[j - 1])
                swap_int(&a[j], &a[j - 1]);
        l++;
    }
}

void selectionSort(int *a, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < size; j++)
            if (a[j] < a[minPos])
                minPos = j;
        swap_int(&a[i], &a[minPos]);
    }
}

void insertSort(int *a, size_t n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && a[j] < a[j - 1]) {
            swap_int(&a[j], &a[j - 1]);
            j--;
        }
    }
}

void combSort(int *a, size_t size) {
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (int i = 0, j = i + step; j < size; ++i, ++j)
            if (a[i] > a[j]) {
                swap_int(&a[i], &a[j]);
                swapped = 1;
            }
    }
}

void even_oddSort(int *a, size_t n) {
    bool even = true;
    bool odd = true;
    while (even || odd) {
        even = false;
        for (int i = 0; i < n; i += 2) {
            if (i + 1 < n && a[i] > a[i + 1]) {
                swap_int(&a[i], &a[i + 1]);
                even = true;
            }
        }
        odd = false;
        for (int i = 1; i < n; i += 2) {
            if (i + 1 < n && a[i] > a[i + 1]) {
                swap_int(&a[i], &a[i + 1]);
                odd = true;
            }
        }
    }
}

void quickSort(int *a, size_t n) {
    qsort(a, n, sizeof(int), compare_ints);
}

void gnomeSort(int *a, size_t n) {
    int *i = a;
    int *end = a + n;
    while (i < end) {
        if (i == a || *(i - 1) <= *i)
            i++;
        else {
            swap_int(i - 1, i);
            i--;
        }
    }
}

void shellSort(int *a, size_t n) {
    int step = n / 2;
    while (step >= 1) {
        for (int i = step; i < n; i++) {
            int j = i;
            int diff = j - step;
            while (diff >= 0 && a[diff] > a[j]) {
                swap_int(&a[diff], &a[j]);
                j = diff;
                diff = j - step;
            }

        }
        step /= 2;
    }
}

int digit(int a, int k, int N, int M) {
    return (a >> (k * N)) & (M - 1);
}

int getMax(int *a, size_t n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (max < a[i])
            max = a[i];
    return max;
}

void radixSort_(int *a, size_t n, int N) {
    int M = (1 << N);
    int max = getMax(a, n);
    int subArray[n];
    int count[M];
    int k = 0;
    while (max) {
        for (int i = 0; i < M; i++)
            count[i] = 0;

        for (int i = 0; i < n; i++)
            count[digit(a[i], k, N, M)]++;

        for (int i = 1; i < M; i++)
            count[i] += count[i - 1];

        for (int i = (int) n - 1; i >= 0; i--) {
            int d = digit(a[i], k, N, M);
            subArray[count[d] - 1] = a[i];
            count[d]--;
        }

        int cur = 0;
        for (int i = 0; i < n; i++)
            a[i] = subArray[cur++];

        max >>= N;
        k++;
    }
}

void radixSort(int *a, size_t n) {
    radixSort_(a, n, 8);
}