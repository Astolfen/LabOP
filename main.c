#include <stdint.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    assert(v.data[0] == 1);
    assert(v.size == 1);
    assert(v.capacity == 1);
    deleteVector(&v);
}

void test_pushBack_fullVector() {
    int a[] = {1, 2, 3, 4, 5};
    vector v = {a, 5, 5};
    pushBack(&v, 1);
    assert(v.data[5] == 1);
    assert(v.size == 6);
    assert(v.capacity == 10);
    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);

    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}

void test_popBack_fullVector() {
    int a[] = {1, 2, 3, 4, 5};
    vector v = {a, 5, 5};
    popBack(&v);
    assert(v.data[v.size-1] == 4);
    assert(v.size == 4);
    assert(v.capacity == 5);
    deleteVector(&v);
}


void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_popBack_fullVector();
}

int main() {
    test();

    return 0;
}
