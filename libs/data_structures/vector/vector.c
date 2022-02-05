#include "vector.h"

vector createVector(size_t n) {
    int *data;
    if (!(data = (int *) malloc(sizeof(int) * n))) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
    return (vector) {data, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    int *buffer = (int *) malloc(v->capacity * sizeof(int));
    memcpy(buffer, v->data, v->capacity * sizeof(int));
    if (!(buffer = (int *) realloc(buffer, newCapacity * sizeof(int)))) {
        free(buffer);
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else if (newCapacity == 0) {
        v->data = NULL;
        v->size = newCapacity;
    } else {
        v->data = buffer;
        if (newCapacity < v->size)
            v->size = newCapacity;
    }
    v->capacity = newCapacity;
    free(buffer);
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}