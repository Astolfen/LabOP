#include "libs/data_structures/void_vector/void_vector.h"

int main() {
    void *a = (void *) malloc(sizeof(int) * 10);
    vectorVoid v = {a,1,10, sizeof(int)};

    return 0;
}