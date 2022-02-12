#include "libs/data_structures/matrix/matrix.h"

int main() {
    matrix *m = getMemArrayOfMatrices(2, 2, 2);

    inputMatrices(m, 2);

    outputMatrices(m, 2);

    freeMemMatrices(m,2);

    return 0;
}