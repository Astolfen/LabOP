#include "void_vector.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    void *data;
    if (!(data = (void *) malloc(sizeof(baseTypeSize) * n))) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
    return (vectorVoid) {data, 0, n};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    void *buffer = (void *) malloc(v->capacity * sizeof(v->baseTypeSize));
    memcpy(buffer, v->data, v->capacity * sizeof(v->baseTypeSize));
    if (!(buffer = (void *) realloc(buffer, newCapacity * sizeof(v->baseTypeSize)))) {
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

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
}