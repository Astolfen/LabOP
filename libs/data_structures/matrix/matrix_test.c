#include "matrix_test.h"

void test_getMemMatrix_freeMemMatrix_NoNull_1() {
    int nRows = 4;
    int nCols = 4;
    matrix m = getMemMatrix(nRows, nCols);
    assert(m.values != NULL);
    assert(nRows == m.nRows);
    assert(nCols == m.nCols);
    freeMemMatrix(m);
}

void test_getMemMatrix_freeMemMatrix_NoNull_2() {
    int nRows = 3;
    int nCols = 1;
    matrix m = getMemMatrix(nRows, nCols);
    assert(m.values != NULL);
    assert(nRows == m.nRows);
    assert(nCols == m.nCols);
    freeMemMatrix(m);
}

void test_getMemMatrix_freeMemMatrix() {
    test_getMemMatrix_freeMemMatrix_NoNull_1();
    test_getMemMatrix_freeMemMatrix_NoNull_2();
}

void test_getMemArrayOfMatrices_freeMemMatrices_NuNull_1() {
    int nMatrices = 4;
    int nRows = 3;
    int nCols = 1;
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    for (int i = 0; i < nMatrices; i++) {
        assert(ms[i].values != NULL);
        assert(ms[i].nRows == nRows);
        assert(ms[i].nCols == nCols);
    }
    freeMemMatrices(ms, nMatrices);
}

void test_getMemArrayOfMatrices_freeMemMatrices_NoNull_2() {
    int nMatrices = 11;
    int nRows = 4;
    int nCols = 4;
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    for (int i = 0; i < nMatrices; i++) {
        assert(ms[i].values != NULL);
        assert(ms[i].nRows == nRows);
        assert(ms[i].nCols == nCols);
    }
    freeMemMatrices(ms, nMatrices);
}

void test_getMemArrayOfMatrices_freeMemMatrices() {
    test_getMemArrayOfMatrices_freeMemMatrices_NuNull_1();
    test_getMemArrayOfMatrices_freeMemMatrices_NoNull_2();
}

void test_swapRows_OneCols() {
    matrix m = createMatrixFromArray((int[]) {1,
                                              2,
                                              3,
                                              4
                                     },
                                     4, 1);
    matrix mRes = createMatrixFromArray((int[]) {4,
                                                 2,
                                                 3,
                                                 1
                                        },
                                        4, 1);

    swapRows(m, 1, 4);
    swapRows(m, 2, 2);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_swapRows_Normal() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9,
                                              10, 11, 12
                                     },
                                     4, 3);
    matrix mRes = createMatrixFromArray((int[]) {1, 2, 3,
                                                 7, 8, 9,
                                                 10, 11, 12,
                                                 4, 5, 6
                                        },
                                        4, 3);

    swapRows(m, 2, 4);
    swapRows(m, 2, 3);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_swapRows() {
    test_swapRows_OneCols();
    test_swapRows_Normal();
}

void test_swapColumns_OneRows() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4},
                                     1, 4);
    matrix mRes = createMatrixFromArray((int[]) {4, 2, 3, 1},
                                        1, 4);

    swapColumns(m, 1, 4);
    swapColumns(m, 2, 2);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_swapColumns_Normal() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9,
                                              10, 11, 12
                                     },
                                     4, 3);
    matrix mRes = createMatrixFromArray((int[]) {2, 3, 1,
                                                 5, 6, 4,
                                                 8, 9, 7,
                                                 11, 12, 10
                                        },
                                        4, 3);

    swapColumns(m, 1, 2);
    swapColumns(m, 2, 3);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_swapColumns() {
    test_swapColumns_OneRows();
    test_swapColumns_Normal();
}

int test_getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > max)
            max = a[i];
    return max;
}

void test_insertionSortRowsMatrixByRowCriteria_OneRows() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4},
                                     1, 4);
    matrix mRes = createMatrixFromArray((int[]) {1, 2, 3, 4},
                                        1, 4);

    insertionSortRowsMatrixByRowCriteria(m, test_getMax);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_insertionSortRowsMatrixByRowCriteria_Normal() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              7, 8, 9,
                                              10, 11, 12,
                                              4, 5, 6
                                     },
                                     4, 3);
    matrix mRes = createMatrixFromArray((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9,
                                                 10, 11, 12
                                        },
                                        4, 3);

    insertionSortRowsMatrixByRowCriteria(m, test_getMax);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_insertionSortRowsMatrixByRowCriteria() {
    test_insertionSortRowsMatrixByRowCriteria_OneRows();
    test_insertionSortRowsMatrixByRowCriteria_Normal();
}

void test_choiceSortColsMatrixByColCriteria_OneCols() {
    matrix m = createMatrixFromArray((int[]) {1,
                                              2,
                                              3,
                                              4
                                     },
                                     4, 1);
    matrix mRes = createMatrixFromArray((int[]) {1,
                                                 2,
                                                 3,
                                                 4
                                        },
                                        4, 1);

    choiceSortColsMatrixByColCriteria(m, test_getMax);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_choiceSortColsMatrixByColCriteria_Normal() {
    matrix m = createMatrixFromArray((int[]) {2, 3, 1,
                                              5, 6, 4,
                                              8, 9, 7,
                                              11, 12, 10
                                     },
                                     4, 3);
    matrix mRes = createMatrixFromArray((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9,
                                                 10, 11, 12
                                        },
                                        4, 3);

    choiceSortColsMatrixByColCriteria(m, test_getMax);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_choiceSortColsMatrixByColCriteria() {
    test_choiceSortColsMatrixByColCriteria_OneCols();
    test_choiceSortColsMatrixByColCriteria_Normal();
}

void test_isSquareMatrix_Square() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9
                                     },
                                     3, 3);

    assert(isSquareMatrix(m));
    freeMemMatrix(m);
}

void test_isSquareMatrix_NoSquare() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9,
                                              10, 11, 12
                                     },
                                     4, 3);

    assert(!isSquareMatrix(m));
    freeMemMatrix(m);
}

void test_isSquareMatrix() {
    test_isSquareMatrix_NoSquare();
    test_isSquareMatrix_Square();
}

void test_twoMatricesEqual_Equal() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9
                                      },
                                      3, 3);

    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_twoMatricesEqual_NoEqualSize() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9,
                                               10, 11, 12
                                      },
                                      4, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9
                                      },
                                      3, 3);

    assert(!twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_twoMatricesEqual_NoEqual() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 6, 6,
                                               7, 8, 9
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {2, 2, 3,
                                               4, 5, 6,
                                               7, 8134, 9
                                      },
                                      3, 3);

    assert(!twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_twoMatricesEqual() {
    test_twoMatricesEqual_Equal();
    test_twoMatricesEqual_NoEqualSize();
    test_twoMatricesEqual_NoEqual();
}

void test_isEMatrix_isE() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1
                                     },
                                     3, 3);

    assert(isEMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix_NoE() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 0, 0,
                                              0, 0, 1
                                     },
                                     3, 3);

    assert(!isEMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix_NoSquare() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9,
                                              10, 11, 12
                                     },
                                     4, 3);

    assert(!isEMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix() {
    test_isEMatrix_isE();
    test_isEMatrix_NoE();
    test_isEMatrix_NoSquare();
}

void test_isSymmetricMatrix_Symmetric() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              2, 1, 4,
                                              3, 4, 1
                                     },
                                     3, 3);

    assert(isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_NoSymmetric() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              3, 1, 4,
                                              4, 2, 1
                                     },
                                     3, 3);

    assert(!isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_NoSquare() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9,
                                              10, 11, 12
                                     },
                                     4, 3);

    assert(!isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_Symmetric();
    test_isSymmetricMatrix_NoSymmetric();
    test_isSymmetricMatrix_NoSquare();
}

void test_transposeSquareMatrix_Normal1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                              5, 6, 7, 8,
                                              9, 10, 11, 12,
                                              13, 14, 15, 16
                                     },
                                     4, 4);
    matrix mRes = createMatrixFromArray((int[]) {1, 5, 9, 13,
                                                 2, 6, 10, 14,
                                                 3, 7, 11, 15,
                                                 4, 8, 12, 16
                                        },
                                        4, 4);

    transposeSquareMatrix(m);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_transposeSquareMatrix_Normal2() {
    matrix m = createMatrixFromArray((int[]) {1
                                     },
                                     1, 1);
    matrix mRes = createMatrixFromArray((int[]) {1
                                        },
                                        1, 1);

    transposeSquareMatrix(m);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_transposeSquareMatrix() {
    test_transposeSquareMatrix_Normal1();
    test_transposeSquareMatrix_Normal2();
}

void test_getMinValuePos_OneMin() {
    matrix m = createMatrixFromArray((int[]) {4, 2, 33, 4,
                                              5, 6, -1, 8,
                                              9, 10, 11, 12
                                     },
                                     3, 4);

    position posMin = getMinValuePos(m);
    assert(posMin.rowIndex == 2);
    assert(posMin.colIndex == 3);
    freeMemMatrix(m);
}

void test_getMinValuePos_SomeMin() {
    matrix m = createMatrixFromArray((int[]) {4, -1, 33, 4,
                                              5, 6, -1, 8,
                                              9, 10, 11, 12
                                     },
                                     3, 4);

    position posMin = getMinValuePos(m);
    assert(posMin.rowIndex == 1);
    assert(posMin.colIndex == 2);
    freeMemMatrix(m);
}

void test_getMinValuePos() {
    test_getMinValuePos_OneMin();
    test_getMinValuePos_SomeMin();
}

void test_getMaxValuePos_OneMax() {
    matrix m = createMatrixFromArray((int[]) {4, -1, 33, 4,
                                              5, 6, 42, 8,
                                              9, 10, 11, 12
                                     },
                                     3, 4);

    position posMax = getMaxValuePos(m);
    assert(posMax.rowIndex == 2);
    assert(posMax.colIndex == 3);
    freeMemMatrix(m);
}

void test_getMaxValuePos_SomeMax() {
    matrix m = createMatrixFromArray((int[]) {4, -1, 33, 4,
                                              5, 6, 33, 8,
                                              9, 10, 11, 12
                                     },
                                     3, 4);

    position posMax = getMaxValuePos(m);
    assert(posMax.rowIndex == 1);
    assert(posMax.colIndex == 3);
    freeMemMatrix(m);
}

void test_getMaxValuePos() {
    test_getMaxValuePos_OneMax();
    test_getMaxValuePos_SomeMax();
}

void test_matrix() {
    test_getMemMatrix_freeMemMatrix();
    test_getMemArrayOfMatrices_freeMemMatrices();
    test_swapRows();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_choiceSortColsMatrixByColCriteria();
    test_isSquareMatrix();
    test_twoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}