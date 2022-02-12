#include "libs/data_structures/matrix/matrix.h"

int main() {
    matrix m = getMemMatrix(2, 2);

    inputMatrix(m);

    swapRows(m, 1, 2);
    swapColumns(m, 1, 2);

    outputMatrix(m);

    freeMemMatrix(m);

    return 0;
}