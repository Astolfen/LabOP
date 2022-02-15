#include "libs/data_structures/matrix/matrix.h"

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > max)
            max = a[i];
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

int main() {

    return 0;
}