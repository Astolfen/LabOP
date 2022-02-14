#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    if (values == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
        ErrorBadAlloc(values[i]);
    }
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    if (ms == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        printf("Matrix %d\n", i + 1);
        outputMatrix(ms[i]);
    }
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1 - 1];
    m.values[i1 - 1] = m.values[i2 - 1];
    m.values[i2 - 1] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++)
        swap_int(&m.values[i][j1 - 1], &m.values[i][j2 - 1]);
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *a = (int *) malloc(sizeof(int) * m.nRows);
    ErrorBadAlloc(a);
    for (int i = 0; i < m.nRows; i++)
        a[i] = criteria(m.values[i], m.nCols);
    //сортировка вставкой
    for (int i = 1; i < m.nRows; i++) {
        int j = i;
        while (a[j] < a[j - 1] && j > 0) {
            swap_int(&a[j], &a[j - 1]);
            swapRows(m, j, j - 1);
            j--;
        }
    }
    free(a);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *a = (int *) malloc(sizeof(int) * m.nCols);
    ErrorBadAlloc(a);
    for (int i = 0; i < m.nCols; i++) {
        int *copyCols = (int *) malloc(sizeof(int) * m.nRows);
        ErrorBadAlloc(copyCols);
        for (int j = 0; j < m.nRows; j++)
            copyCols[j] = m.values[j][i];
        a[i] = criteria(copyCols, m.nRows);
        free(copyCols);
    }
    //сортировка вставкой
    for (int i = 1; i < m.nCols; i++) {
        int j = i;
        while (a[j] < a[j - 1] && j > 0) {
            swap_int(&a[j], &a[j - 1]);
            swapColumns(m, j, j - 1);
            j--;
        }
    }
    free(a);
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m1.nCols; j++)
            if (m1.values[i][j] != m2.values[i][j])
                return false;
    return true;
}

bool isEMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    for (int i = 0; i < m.nRows; i++) {
        if (m.values[i][i] != 1)
            return false;
        for (int j = i + 1; j < m.nCols; j++)
            if (m.values[i][j] != m.values[j][i] && m.values[i][j] != 0)
                return false;
    }
    return true;
}

bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    for (int i = 0; i < m.nRows; i++)
        for (int j = i + 1; j < m.nCols; j++)
            if (m.values[i][j] != m.values[j][i])
                return false;
    return true;
}