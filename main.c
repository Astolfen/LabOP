#include "libs/data_structures/void_vector/void_vector.h"
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
    assert(v.data[v.size - 1] == 4);
    assert(v.size == 4);
    assert(v.capacity == 5);
}

void test_atVector_notEmptyVector() {
    int a[] = {7, 2, 9, 2, 5};
    vector v = {a, 3, 5};
    int *b = atVector(&v, 1);
    assert(b == &v.data[1]);
}

void test_atVector_requestToLastElement() {
    int a[] = {7, 2, 9, 2, 5};
    vector v = {a, 5, 5};
    int *b = atVector(&v, 4);
    assert(b == &v.data[4]);
}

void test_back_oneElementInVector() {
    int a[] = {7, 2, 9, 2, 5};
    vector v = {a, 1, 5};
    int *b = back(&v);
    assert(b == &v.data[0]);
}

void test_back_NormalVector() {
    int a[] = {12, 12, 9, 2, 5};
    vector v = {a, 2, 5};
    int *b = back(&v);
    assert(b == &v.data[1]);
}

void test_front_oneElementInVector() {
    int a[] = {7, 2, 9, 2, 5};
    vector v = {a, 1, 5};
    int *b = front(&v);
    assert(b == &v.data[0]);
}

void test_front_NormalVector() {
    int a[] = {7, 2, 9, 2, 5};
    vector v = {a, 3, 5};
    int *b = front(&v);
    assert(b == &v.data[0]);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_popBack_fullVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
    test_front_NormalVector();
    test_back_NormalVector();
}

int main() {
    test();

    size_t n;
    scanf("%zd", &n);

    vectorVoid v = createVectorV(0, sizeof(float));
    for (int i = 0; i < n; i++) {
        float x;
        scanf("%f", &x);

        pushBackV(&v, &x);
    }

    for (int i = 0; i < n; i++) {
        float x;
        getVectorValueV(&v, i, &x);

        printf("%f ", x);
    }

    return 0;
}