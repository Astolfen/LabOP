#include "matrix_task.h"

void task1(matrix m) {
    position p1 = getMaxValuePos(m);
    position p2 = getMinValuePos(m);
    if (p1.rowIndex != p2.rowIndex)
        swapRows(m, p1.rowIndex, p2.rowIndex);
}

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > max)
            max = a[i];
    return max;
}

void task2(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] < min)
            min = a[i];
    return min;
}

void task3(matrix m) {
    choiceSortColsMatrixByColCriteria(m, getMin);
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

void task4(matrix *m) {
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

void task5(matrix m) {
    long long *a = (long long *) malloc(sizeof(long long) * m.nRows);
    for (int i = 0; i < m.nRows; i++)
        a[i] = getSum(m.values[i], m.nCols);

    if (isUnique(a, m.nRows))
        transposeSquareMatrix(m);
    free(a);
}

bool task6(matrix m1, matrix m2) {
    matrix mul = mulMatrices(m1, m2);
    bool res = isEMatrix(mul);
    freeMemMatrix(mul);
    return res;
}

int max2_int(int a, int b) {
    return a > b ? a : b;
}

int task7(matrix m) {
    int n = m.nRows + m.nCols - 1;
    int *a = (int *) calloc(n, sizeof(int));

    int start_index = m.nRows - 1;
    int sum = 0;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (i != j) {
                int iWrite = start_index + j - i;
                if (i == 0 || j == 0)
                    a[iWrite] = m.values[i][j];
                else
                    a[iWrite] = max2_int(a[iWrite], m.values[i][j]);
            }

    for (int i = 0; i < n; i++)
        sum += a[i];
    free(a);
    return sum;
}

int task8(matrix m) {
    position maxP = getMaxValuePos(m);
    int i = maxP.rowIndex - 1;
    int l = maxP.colIndex - 1;
    int r = maxP.colIndex - 1;
    int min = m.values[i][l];
    while (i > 0) {
        i--;
        if (l > 0) l--;
        if (r < m.nCols - 1) r++;
        int newMin = getMin(m.values[i] + l, r - l + 1);
        if (min > newMin)
            min = newMin;
    }

    return min;
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
            swapRows(m, j + 1, j);
            j--;
        }
    }

    free(a);
}

void task9(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int countNUnique(long long *a, int n) {
    int count = 1;
    long long last = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] != last) {
            count++;
            last = a[i];
        }
    return count;
}

int task10(matrix m) {
    long long *a = (long long *) malloc(sizeof(long long) * m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        long long sum = 0;
        for (int j = 0; j < m.nCols; j++)
            sum += m.values[i][j];
        a[i] = sum;
    }
    qsort(a, m.nRows, sizeof(long long), cmp_long_long);

    int res = countNUnique(a, m.nRows);
    free(a);
    return res;
}

bool checkHaveUniqueElement(matrix m, int j) {
    int max = m.values[0][j];
    int sum = m.values[0][j];
    for (int i = 1; i < m.nRows; i++) {
        sum += m.values[i][j];
        if (max < m.values[i][j])
            max = m.values[i][j];
    }
    return sum - max < max;
}

int task11(matrix m) {
    int count = 0;
    for (int i = 0; i < m.nCols; i++)
        count += checkHaveUniqueElement(m, i);

    return count;
}

void task12(matrix m) {
    assert(isSquareMatrix(m));
    int minElementCols = getMinValuePos(m).colIndex - 1;
    for (int i = m.nRows - 1; i >= 0; i--)
        m.values[m.nRows - 2][i] = m.values[i][minElementCols];
}

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;
    return true;
}

int task13(matrix *ms, int n) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (hasAllNonDescendingRows(ms[i]))
            count += 1;

    return count;
}

int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == value)
            count += 1;
    return count;
}

int countZeroRows(matrix m) {
    int count = 0;
    for (int i = 0; i < m.nRows; i++)
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            count += 1;
    return count;
}

void task14(matrix *ms, int n) {
    int a[n];
    int sizeA = 0;
    int maxZero = 0;
    for (int i = 0; i < n; i++) {
        int count = countZeroRows(ms[i]);
        if (sizeA == 0 || maxZero < count) {
            sizeA = 1;
            a[sizeA - 1] = i;
            maxZero = count;
        } else if (count == maxZero) {
            sizeA += 1;
            a[sizeA - 1] = i;
        }
    }

    for (int i = 0; i < sizeA; i++) {
        outputMatrix(ms[a[i]]);
    }
}

float getMaxValueFAbs(matrixf m) {
    int maxPosI = 0;
    int maxPosJ = 0;
    float max = fabsf(m.values[maxPosI][maxPosJ]);
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (max < fabsf(m.values[i][j])) {
                maxPosI = i;
                maxPosJ = j;
                max = fabsf(m.values[maxPosI][maxPosJ]);
            }
    return max;
}

void task15(matrixf *ms, int n){
    int a[n];
    int sizeA = 0;
    float minNorms = 0;
    for (int i = 0; i < n; i++) {
        float norms = getMaxValueFAbs(ms[i]);
        if (sizeA == 0 || minNorms > norms) {
            sizeA = 1;
            a[sizeA - 1] = i;
            minNorms = norms;
        } else if (fabsf(norms - minNorms) < DBL_EPSILON) {
            sizeA += 1;
            a[sizeA - 1] = i;
        }
    }
    for (int i = 0; i < sizeA; i++)
        outputMatrixF(ms[a[i]]);
}