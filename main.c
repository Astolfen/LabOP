#include "libs/data_structures/matrix/matrix.h"

//#define TASK1
//#define TASK2
//#define TASK3
//#define TASK4
//#define TASK5
//#define TASK6
//#define TASK7
//#define TASK8
//#define TASK9
#define TASK10

int max2_int(int a, int b) {
    return a > b ? a : b;
}

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > max)
            max = a[i];
    return max;
}

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] < min)
            min = a[i];
    return min;
}

//тудаже
int mulRowsOnCols(matrix m1, int index1, matrix m2, int index2) {
    int mul = 0;
    int i = m1.nCols - 1;
    while (i >= 0) {
        mul += m1.values[index1][i] * m2.values[i][index2];
        i--;
    }
    return mul;
}

//перенести  в бибилотеку
matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows) {
        fprintf(stderr, "you can't multiply ");
        exit(1);
    }
    matrix mRes = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++)
            mRes.values[i][j] = mulRowsOnCols(m1, i, m2, j);
    return mRes;
}

bool isUnique(long long *a, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return false;
    return true;
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

float getDistance(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * a[i];
    return sqrtf((float) sum);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float *a = (float *) malloc(sizeof(float) * m.nRows);
    if (a == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
    for (int i = 0; i < m.nRows; i++)
        a[i] = criteria(m.values[i], m.nCols);
    //сортировка вставкой
    for (int i = 1; i < m.nRows; i++) {
        int j = i;
        while (a[j] < a[j - 1] && j > 0) {
            swap_float(&a[j], &a[j - 1]);
            swapRows(m, j, j - 1);
            j--;
        }
    }
    free(a);
}

int main() {
#ifdef TASK1
    matrix m = getMemMatrix(3, 4);
    inputMatrix(m);

    position p1 = getMaxValuePos(m);
    position p2 = getMaxValuePos(m);
    if (p1.rowIndex != p2.rowIndex)
        swapRows(m, p1.rowIndex, p2.rowIndex);

    outputMatrix(m);
    freeMemMatrix(m);
#endif

#ifdef TASK2
    matrix m = getMemMatrix(3, 4);
    inputMatrix(m);

    insertionSortRowsMatrixByRowCriteria(m, getMax);

    outputMatrix(m);
    freeMemMatrix(m);
#endif

#ifdef TASK3
    matrix m = getMemMatrix(3, 4);
    inputMatrix(m);

    choiceSortColsMatrixByColCriteria(m, getMin);

    outputMatrix(m);
    freeMemMatrix(m);
#endif

#ifdef TASK4
    matrix m = getMemMatrix(3, 4);
    inputMatrix(m);

    if (isSymmetricMatrix(m)) {
        matrix mRes = mulMatrices(m, m);
        freeMemMatrix(m);
        m = mRes;
        freeMemMatrix(mRes);
    }

    outputMatrix(m);
    freeMemMatrix(m);
#endif

#ifdef TASK5
    matrix m = getMemMatrix(3, 4);
    inputMatrix(m);

    long long *a = (long long *) malloc(sizeof(long long) * m.nRows);
    for (int i = 0; i < m.nRows; i++)
        a[i] = getSum(m.values[i], m.nCols);

    if (isUnique(a, m.nRows))
        transposeSquareMatrix(m);
    free(a);

    outputMatrix(m);
    freeMemMatrix(m);
#endif

#ifdef TASK6
    matrix m1 = getMemMatrix(3, 4);
    inputMatrix(m1);
    matrix m2 = getMemMatrix(3, 4);
    inputMatrix(m2);

    matrix mul = mulMatrices(m1, m2);
    bool res = isEMatrix(mul);

    //outputMatrix(mul);
    freeMemMatrix(mul);
    freeMemMatrix(m1);
    freeMemMatrix(m2);

    printf("\n%d", res);
#endif

#ifdef TaSK7
    //pls но
#endif

#ifdef TASK8
    matrix m = getMemMatrix(3, 4);
    inputMatrix(m);

    position maxP = getMaxValuePos(m);
    int i = maxP.rowIndex;
    int l = maxP.colIndex;
    int r = maxP.colIndex;
    int min = m.values[i][l];
    while (i >= 0) {
        l = l == 0 ? l : (l - 1);
        r = r == m.nCols - 1 ? r : (r + 1);
        int newMin = getMin(m.values[i] + l, r - l - 1);
        if (min > newMin)
            min = newMin;
        i--;
    }

    freeMemMatrix(m);

    printf("\n%d", min);
#endif

#ifdef TASK9
    matrix m = getMemMatrix(3, 4);
    inputMatrix(m);

    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);

    outputMatrix(m);
    freeMemMatrix(m);
#endif

#ifdef TASK10
    matrix m = getMemMatrix(3, 4);
    inputMatrix(m);



    freeMemMatrix(m);
#endif

    return 0;
}

//int maxInDiagonal(matrix m, int i, int j) {
//    int max = m.values[i][j];
//    while (i < m.nCols && j < m.nRows) {
//        max = max2_int(max, m.values[i][j]);
//        i++;
//        j++;
//    }
//    return max;
//}
//
//long long sevenTask(matrix m) {
//    long long sum = 0;
//    for (int i = 1; i < m.nCols; i++)
//        sum += maxInDiagonal(m, 0, i);
//    for (int i = 1; i < m.nRows; i++)
//        sum += maxInDiagonal(m, i, 0);
//    return sum;
//}