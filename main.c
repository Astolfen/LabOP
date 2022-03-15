#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "libs/algorithms/algorithm.h"
#include "libs/algorithms/array/array.h"

#define TIME_TEST(testCode, time) { \
 clock_t start_time = clock (); \
 testCode \
 clock_t end_time = clock (); \
 clock_t sort_time = end_time - start_time; \
 time = (double) sort_time / CLOCKS_PER_SEC; \
 }

#define ARRAY_SIZE(a) sizeof(a) / sizeof (a[0])

//функция сортировки
typedef struct SortFunc {
    void (*sort )(int *a, size_t n);    // указатель на функцию сортировки

    char name[64];                      // имя сортировки,используемое при выводе
} SortFunc;

//функция генерации
typedef struct GeneratingFunc {
    void (*generate )(int *a, size_t n);    //указатель на функцию генерации последоват.

    char name[64];                          //имя генератора,используемое при выводе
} GeneratingFunc;

void generateRandomArray(int *a, size_t n);

void generateOrderedArray(int *a, size_t n);

void generateOrderedBackwards(int *a, size_t n);

bool isOrdered(const int *a, size_t n) {
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

void checkTime(void (*sortFunc )(int *, size_t), void (*generateFunc)(int *, size_t),
               size_t size, char *experimentName) {
    static size_t runCounter = 1;

    // генерация последовательности
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf(" Name : %s\n", experimentName);
    // замер времени
    double time;
    TIME_TEST ({ sortFunc(innerBuffer, size); }, time)

    // результаты замера
    printf(" Status : ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time : %.3f s.\n", time);

        // запись в файл
//        char name[] = "test_time";
        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf(" FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    } else {
        printf(" Wrong!\n");

        // вывод массива, который не смог быть отсортирован
        outputArray_(innerBuffer, size);

        exit(1);
    }
}

void timeExperiment() {
    // описание функций сортировки
    SortFunc sorts[] = {
            {bubbleSort, " bubbleSort "},
            {selectionSort, " selectionSort "},
            {insertSort, " insertionSort "},
            {combSort,   " combSort "}, // расческа
            {shakerSort, " shakerSort "},
            {even_oddSort, " even_oddSort "},
            {quickSort, " quickSort "},
            {gnomeSort, " gnomeSort "},
            {shellSort, " shellSort "},
            {radixSort, " radixSort "}
    };
    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    // описание функций генерации
    GeneratingFunc generatingFuncs[] = {
            // генерируется случайный массив
            {generateRandomArray,      " random1 "},
            {generateRandomArray,      " random2 "},
            {generateRandomArray,      " random3 "},
            // генерируется массив 0, 1, 2, ..., n - 1
            {generateOrderedArray,     " ordered "},
            // генерируется массив n - 1, n - 2, ..., 0
            {generateOrderedBackwards, " orderedBackwards "}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

    // запись статистики в файл
    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf(" Size : %d\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                // генерация имени файла
                static char filename[128];
                sprintf(filename, "%s_%s_time ",
                        sorts[i].name, generatingFuncs[j].name);
                checkTime(sorts[i].sort,
                          generatingFuncs[j].generate,
                          size, filename);
            }
        }
        printf("\n");
    }
}

int main() {
    timeExperiment();
//    int n = 5;
//    int a[5] = {8, 2, 5, 2, 1};
//
//    radixSort(a, n);
//
//    outputArray_(a, n);

    return 0;
}

void generateRandomArray(int *a, size_t n) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        a[i] = rand() % n;
}

void generateOrderedArray(int *a, size_t n) {
    for (int i = 0; i < n; i++)
        a[i] = i;
}

void generateOrderedBackwards(int *a, size_t n) {
    for (int i = 0; i < n; i++)
        a[i] = n - i - 1;
}