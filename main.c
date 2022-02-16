#include "libs/data_structures/matrix/matrix.h"

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > max)
            max = a[i];
}

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] < min)
            min = a[i];
}

int mulRowsOnCols(matrix m1, int index1, matrix m2, int index2) {
    int mul = 0;
    int i = m1.nCols - 1;
    while (i >= 0) {
        mul += m1.values[index1][i] * m2.values[i][index2];
        i--;
    }
    return mul;
}

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

void firstTask(matrix m) {
    position p1 = getMaxValuePos(m);
    position p2 = getMaxValuePos(m);
    if (p1.rowIndex != p2.rowIndex)
        swapRows(m, p1.rowIndex, p2.rowIndex);
}

void secondTask(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void thirdTask(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void fourthTask(matrix *m) {
    if (isSymmetricMatrix(*m)) {
        matrix mRes = mulMatrices(*m, *m);
        freeMemMatrix(*m);
        *m = mRes;
    }
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

void fiveTask(matrix m, int nRows, int nCols) {
    long long *a = (long long *) malloc(sizeof(long long) * nRows);
    for (int i = 0; i < nRows; i++)
        a[i] = getSum(m.values[i], nCols);

    if (isUnique(a, nRows))
        transposeSquareMatrix(m);

    free(a);
}


int main() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               2, 3, 4,
                                               3, 4, 5}, 3, 3);
    fourthTask(&m1);
    outputMatrix(m1);

    return 0;
}