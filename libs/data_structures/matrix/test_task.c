#include "test_task.h"

void test_task1_MaxMInInDifferentRows() {
    matrix m = createMatrixFromArray((int[]) {4, 2, 33,
                                              5, 6, 1,
                                              9, 10, 11
                                     },
                                     3, 3);
    matrix mRes = createMatrixFromArray((int[]) {5, 6, 1,
                                                 4, 2, 33,
                                                 9, 10, 11
                                        },
                                        3, 3);
    task1(m);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}


void test_task1_MaxMInInOneRow() {
    matrix m = createMatrixFromArray((int[]) {4, 2, 3,
                                              5, 36, 1,
                                              9, 10, 11
                                     },
                                     3, 3);
    matrix mRes = createMatrixFromArray((int[]) {4, 2, 3,
                                                 5, 36, 1,
                                                 9, 10, 11
                                        },
                                        3, 3);
    task1(m);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}


void test_task1() {
    test_task1_MaxMInInDifferentRows();
    test_task1_MaxMInInOneRow();
}

void test_task2_AllElementUnique() {
    matrix m = createMatrixFromArray((int[]) {4, 2, 33,
                                              5, 6, 1,
                                              9, 10, 11
                                     },
                                     3, 3);
    matrix mRes = createMatrixFromArray((int[]) {5, 6, 1,
                                                 9, 10, 11,
                                                 4, 2, 33
                                        },
                                        3, 3);
    task2(m);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_task2_NoUniqueElement() {
    matrix m = createMatrixFromArray((int[]) {4, 2, 33,
                                              5, 6, 10,
                                              9, 10, 11
                                     },
                                     3, 3);
    matrix mRes = createMatrixFromArray((int[]) {5, 6, 10,
                                                 9, 10, 11,
                                                 4, 2, 33
                                        },
                                        3, 3);
    task2(m);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_task2() {
    test_task2_AllElementUnique();
    test_task2_NoUniqueElement();
}

void test_task3_AllElementUnique() {
    matrix m = createMatrixFromArray((int[]) {4, 2, 33,
                                              5, 6, 1,
                                              9, 10, 11
                                     },
                                     3, 3);
    matrix mRes = createMatrixFromArray((int[]) {33, 2, 4,
                                                 1, 6, 5,
                                                 11, 10, 9
                                        },
                                        3, 3);
    task3(m);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_task3_NoUniqueElement() {
    matrix m = createMatrixFromArray((int[]) {4, 2, 33,
                                              5, 6, 2,
                                              9, 10, 11
                                     },
                                     3, 3);
    matrix mRes = createMatrixFromArray((int[]) {2, 33, 4,
                                                 6, 2, 5,
                                                 10, 11, 9
                                        },
                                        3, 3);
    task3(m);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_task3() {
    test_task3_AllElementUnique();
    test_task3_NoUniqueElement();
}

void test_mulMatrices_1() {
    matrix m1 = createMatrixFromArray((int[]) {2, 3, 4,
                                               53, 432, 0,
                                               3, 21, 2
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 32, 43,
                                               43, 1, 23,
                                               6, 31, 0
                                      },
                                      3, 3);
    matrix mRes = createMatrixFromArray((int[]) {155, 191, 155,
                                                 18629, 2128, 12215,
                                                 918, 179, 612
                                        },
                                        3, 3);
    matrix m = mulMatrices(m1, m2);
    freeMemMatrix(m1);
    freeMemMatrix(m2);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_mulMatrices_2() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               6, 5, 4,
                                               7, 8, 9
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1,
                                               2,
                                               3
                                      },
                                      3, 1);
    matrix mRes = createMatrixFromArray((int[]) {14,
                                                 28,
                                                 50
                                        },
                                        3, 1);
    matrix m = mulMatrices(m1, m2);
    freeMemMatrix(m1);
    freeMemMatrix(m2);
    assert(m.nRows == mRes.nRows);
    assert(m.nCols == mRes.nCols);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_task4_EMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1
                                     },
                                     3, 3);
    matrix mRes = createMatrixFromArray((int[]) {1, 0, 0,
                                                 0, 1, 0,
                                                 0, 0, 1
                                        },
                                        3, 3);
    task4(&m);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_task4_Normal() {
    matrix m = createMatrixFromArray((int[]) {4, 2, 5,
                                              2, 6, 8,
                                              5, 8, 11
                                     },
                                     3, 3);
    matrix mRes = createMatrixFromArray((int[]) {45, 60, 91,
                                                 60, 104, 146,
                                                 91, 146, 210
                                        },
                                        3, 3);
    task4(&m);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_task4() {
    test_mulMatrices_1();
    test_mulMatrices_2();
    test_task4_EMatrix();
    test_task4_Normal();
}

void test_task5_1() {
    matrix m = createMatrixFromArray((int[]) {4, 2, 33,
                                              5, 6, 10,
                                              9, 10, 11
                                     },
                                     3, 3);
    matrix mRes = createMatrixFromArray((int[]) {4, 5, 9,
                                                 2, 6, 10,
                                                 33, 10, 11
                                        },
                                        3, 3);
    task5(m);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_task5_2() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              3, 2, 1,
                                              2, 2, 1
                                     },
                                     3, 3);
    matrix mRes = createMatrixFromArray((int[]) {1, 2, 3,
                                                 3, 2, 1,
                                                 2, 2, 1
                                        },
                                        3, 3);
    task5(m);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_task5() {
    test_task5_1();
    test_task5_2();
}

void test_task6_1() {
    matrix m1 = createMatrixFromArray((int[]) {3, -5,
                                               1, -2
                                      },
                                      2, 2);
    matrix m2 = createMatrixFromArray((int[]) {2, -5,
                                               1, -3
                                      },
                                      2, 2);
    assert(task6(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_task6_2() {
    matrix m1 = createMatrixFromArray((int[]) {1, 3, -5,
                                               0, 1, 2,
                                               0, 0, 1
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, -3, 11,
                                               0, 1, -2,
                                               0, 0, 1
                                      },
                                      3, 3);
    assert(task6(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_task6() {
    test_task6_1();
    test_task6_2();
}

void test_task7_1() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                              1, 3, 6, 3,
                                              3, 2, 1, 2
                                     },
                                     3, 4);
    assert(task7(m) == 20);
    freeMemMatrix(m);
}

void test_task7() {
    test_task7_1();
}

void test_task8_1() {
    matrix m = createMatrixFromArray((int[]) {10, 7, 5, 6,
                                              3, 11, 8, 9,
                                              4, 1, 12, 2
                                     },
                                     3, 4);
    assert(task8(m) == 5);
    freeMemMatrix(m);
}

void test_task8() {
    test_task8_1();
}

//девятая не нуждаеться в проверке
// т.к. код полность индентичен уже провереной функции

void test_task10_1() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                              2, 7,
                                              5, 4,
                                              4, 3,
                                              1, 6,
                                              8, 0
                                     },
                                     6, 2);
    assert(task10(m) == 3);
    freeMemMatrix(m);
}

void test_task10() {
    test_task10_1();
}

void test_task11_1() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                              2, 3, 6, 7,
                                              12, 2, 2, 1
                                     },
                                     3, 4);
    assert(task11(m) == 2);
    freeMemMatrix(m);
}

void test_task11() {
    test_task11_1();
}

void test_task12_1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 1
                                     },
                                     3, 3);
    matrix mRes = createMatrixFromArray((int[]) {1, 2, 3,
                                                 1, 4, 7,
                                                 7, 8, 1
                                        },
                                        3, 3);
    task12(m);
    for (int i = 0; i < m.nRows; i++)
        assert(!memcmp(m.values[i], mRes.values[i], m.nCols * sizeof(int)));
    freeMemMatrix(m);
    freeMemMatrix(mRes);
}

void test_task12() {
    test_task12_1();
}

void test_task13_1() {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * 4);

    ms[0] = createMatrixFromArray((int[]) {7, 1,
                                           1, 1
                                  },
                                  2, 2);
    ms[1] = createMatrixFromArray((int[]) {1, 6,
                                           2, 2
                                  },
                                  2, 2);
    ms[2] = createMatrixFromArray((int[]) {5, 4,
                                           2, 3
                                  },
                                  2, 2);
    ms[3] = createMatrixFromArray((int[]) {1, 3,
                                           7, 9
                                  },
                                  2, 2);

    assert(task13(ms, 4) == 2);
    freeMemMatrices(ms, 4);
}

void test_task13() {
    test_task13_1();
}

void test_countZeroRows_1() {
    matrix m = createMatrixFromArray((int[]) {0, 0, 0,
                                              4, 0, 6,
                                              0, 0, 0
                                     },
                                     3, 3);
    assert(countZeroRows(m) == 2);
    freeMemMatrix(m);
}

void test_countZeroRows() {
    test_countZeroRows_1();
}

void test_task() {
    test_task1();
    test_task2();
    test_task3();
    test_task4();
    test_task5();
    test_task6();
    test_task7();
    test_task8();
    test_task10();
    test_task11();
    test_task12();
    test_task13();
    test_countZeroRows();
}