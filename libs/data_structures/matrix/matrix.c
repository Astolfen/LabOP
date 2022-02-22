#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    if (nRows == 0 || nCols == 0) {
        fprintf(stderr, "men wtf. Don't be silly. ");
        exit(1);
    }
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
    if (nMatrices == 0) {
        fprintf(stderr, "men wtf. Don't be silly. ");
        exit(1);
    }
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
    if (i1 <= 0 || i2 <= 0) {
        fprintf(stderr, "one index does not exist ");
        exit(1);
    }
    int *t = m.values[i1 - 1];
    m.values[i1 - 1] = m.values[i2 - 1];
    m.values[i2 - 1] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    if (j1 <= 0 || j2 <= 0) {
        fprintf(stderr, "one index does not exist ");
        exit(1);
    }
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
            swapRows(m, j + 1, j);
            j--;
        }
    }
    free(a);
}

void choiceSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
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
    //сортировка выбором
    for (int i = 0; i < m.nCols; i++) {
        int minPos = getMinIndex(a, m.nCols, i);
        swap_int(&a[i], &a[minPos]);
        swapColumns(m, i + 1, minPos + 1);
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
        if (memcmp(m1.values[i], m2.values[i], sizeof(int) * m1.nCols))
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

void transposeSquareMatrix(matrix m) {
    if (!isSquareMatrix(m)) {
        fprintf(stderr, "matrix is not square");
        exit(1);
    }
    for (int i = 0; i < m.nRows; i++)
        for (int j = i + 1; j < m.nCols; j++)
            swap_int(&m.values[i][j], &m.values[j][i]);
}

position getMinValuePos(matrix m) {
    int minPosI = 0;
    int minPosJ = 0;
    int min = m.values[minPosI][minPosJ];
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (min > m.values[i][j]) {
                minPosI = i;
                minPosJ = j;
                min = m.values[minPosI][minPosJ];
            }
    return (position) {minPosI + 1, minPosJ + 1};
}

position getMaxValuePos(matrix m) {
    int maxPosI = 0;
    int maxPosJ = 0;
    int max = m.values[maxPosI][maxPosJ];
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (max < m.values[i][j]) {
                maxPosI = i;
                maxPosJ = j;
                max = m.values[maxPosI][maxPosJ];
            }
    return (position) {maxPosI + 1, maxPosJ + 1};
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];
    return m;
}

matrix *createArrayOfMatrixFromArray(const int *a, int nMatrices, int nRows, int nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = a[l++];
    return ms;
}

matrixf getMemMatrixF(int nRows, int nCols) {
    if (nRows == 0 || nCols == 0) {
        fprintf(stderr, "men wtf. Don't be silly. ");
        exit(1);
    }
    float **values = (float **) malloc(sizeof(float *) * nRows);
    if (values == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
    for (int i = 0; i < nRows; i++) {
        values[i] = (float *) malloc(sizeof(float) * nCols);
        if (values[i] == NULL) {
            fprintf(stderr, "bad alloc ");
            exit(1);
        }
    }
    return (matrixf) {values, nRows, nCols};
}

matrixf *getMemArrayOfMatricesF(int nMatrices, int nRows, int nCols) {
    if (nMatrices == 0) {
        fprintf(stderr, "men wtf. Don't be silly. ");
        exit(1);
    }
    matrixf *ms = (matrixf *) malloc(sizeof(matrixf) * nMatrices);
    if (ms == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrixF(nRows, nCols);
    return ms;
}

void freeMemMatrixF(matrixf m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatricesF(matrixf *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrixF(ms[i]);
    free(ms);
}

void inputMatrixF(matrixf m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            scanf("%f", &m.values[i][j]);
}

void inputMatricesF(matrixf *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrixF(ms[i]);
}

void outputMatrixF(matrixf m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%f ", m.values[i][j]);
        printf("\n");
    }
}

void outputMatricesF(matrixf *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        printf("Matrix %d\n", i + 1);
        outputMatrixF(ms[i]);
    }
}