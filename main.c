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
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

int main() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               2, 3, 4,
                                               3, 4, 5}, 3, 3);
    fourthTask(&m1);
    outputMatrix(m1);

    return 0;
}