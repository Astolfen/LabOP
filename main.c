#include "libs/data_structures/matrix/matrix.h"

void firstTask(matrix m) {
    position p1 = getMaxValuePos(m);
    position p2 = getMaxValuePos(m);
    if (p1.rowIndex != p2.rowIndex)
        swapRows(m, p1.rowIndex, p2.rowIndex);
}

int main() {

    return 0;
}