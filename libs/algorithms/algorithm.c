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

long long bubbleSort(int *a, size_t n) {
    long long nComps = 0;
    for (int i = 0; ++nComps && i < n - 1; i++) {
        for (int j = 0; ++nComps && j < n - 1 - i; ++j) {
            if (++nComps && a[j] > a[j + 1])
                swap_int(&a[j], &a[j + 1]);
        }
    }

    return nComps;
}

long long shakerSort(int *a, size_t n) {
    long long nComps = 0;
    int l = 0;
    int r = (int) n - 1;
    while (++nComps && l < r) {
        for (int j = l; ++nComps && j < r; j++)
            if (++nComps && a[j] > a[j + 1])
                swap_int(&a[j], &a[j + 1]);
        r--;
        for (int j = r; ++nComps && j > l; j--)
            if (++nComps && a[j] < a[j - 1])
                swap_int(&a[j], &a[j - 1]);
        l++;
    }

    return nComps;
}

long long selectionSort(int *a, size_t size) {
    long long nComps = 0;
    for (int i = 0; ++nComps && i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; ++nComps && j < size; j++)
            if (++nComps && a[j] < a[minPos])
                minPos = j;
        swap_int(&a[i], &a[minPos]);
    }

    return nComps;
}

long long insertSort(int *a, size_t n) {
    long long nComps = 0;
    for (int i = 1; ++nComps && i < n; i++) {
        int j = i;
        while (++nComps && j > 0 && a[j] < a[j - 1]) {
            swap_int(&a[j], &a[j - 1]);
            j--;
        }
    }
    return nComps;
}

long long combSort(int *a, size_t size) {
    long long nComps = 0;
    size_t step = size;
    int swapped = 1;
    while (++nComps && step > 1 || swapped) {
        if (++nComps && step > 1)
            step /= 1.24733;
        swapped = 0;
        for (int i = 0, j = i + step; ++nComps && j < size; ++i, ++j)
            if (++nComps && a[i] > a[j]) {
                swap_int(&a[i], &a[j]);
                swapped = 1;
            }
    }
    return nComps;
}

long long even_oddSort(int *a, size_t n) {
    long long nComps = 0;
    bool even = true;
    bool odd = true;
    while (++nComps && even || odd) {
        even = false;
        for (int i = 0; ++nComps && i < n; i += 2) {
            if (++nComps && i + 1 < n && a[i] > a[i + 1]) {
                swap_int(&a[i], &a[i + 1]);
                even = true;
            }
        }
        odd = false;
        for (int i = 1; ++nComps && i < n; i += 2) {
            if (++nComps && i + 1 < n && a[i] > a[i + 1]) {
                swap_int(&a[i], &a[i + 1]);
                odd = true;
            }
        }
    }
    return nComps;
}

long long quickSort(int *a, size_t n) {
    qsort(a, n, sizeof(int), compare_ints);
    return 0;
}

long long gnomeSort(int *a, size_t n) {
    long long nComps = 0;
    int *i = a;
    int *end = a + n;
    while (++nComps && i < end) {
        if (++nComps && i == a || *(i - 1) <= *i)
            i++;
        else {
            swap_int(i - 1, i);
            i--;
        }
    }
    return nComps;
}

long long shellSort(int *a, size_t n) {
    long long nComps = 0;
    int step = n / 2;
    while (++nComps && step >= 1) {
        for (int i = step; ++nComps && i < n; i++) {
            int j = i;
            int diff = j - step;
            while (++nComps && diff >= 0 && a[diff] > a[j]) {
                swap_int(&a[diff], &a[j]);
                j = diff;
                diff = j - step;
            }

        }
        step /= 2;
    }
    return nComps;
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

long long radixSort_(int *a, size_t n, int N) {
    long long nComps = 0;
    int M = (1 << N);
    int max = getMax(a, n);
    int subArray[n];
    int count[M];
    int k = 0;
    while (++nComps && max) {
        for (int i = 0; ++nComps && i < M; i++)
            count[i] = 0;

        for (int i = 0; ++nComps && i < n; i++)
            count[digit(a[i], k, N, M)]++;

        for (int i = 1; ++nComps && i < M; i++)
            count[i] += count[i - 1];

        for (int i = (int) n - 1; ++nComps && i >= 0; i--) {
            int d = digit(a[i], k, N, M);
            subArray[count[d] - 1] = a[i];
            count[d]--;
        }

        int cur = 0;
        for (int i = 0; ++nComps && i < n; i++)
            a[i] = subArray[cur++];

        max >>= N;
        k++;
    }
    return nComps;
}

long long radixSort(int *a, size_t n) {
    return radixSort_(a, n, 8);
}