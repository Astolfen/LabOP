#include "void_vector.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    void *data;
    if (!(data = (void *) malloc(sizeof(baseTypeSize) * n))) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
    return (vectorVoid) {data, 0, n,baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (!(v->data = (void *) realloc(v->data, newCapacity * sizeof(v->baseTypeSize)))) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else if (newCapacity == 0) {
        v->data = NULL;
        v->size = newCapacity;
    } else if (newCapacity < v->size)
        v->size = newCapacity;
    v->capacity = newCapacity;
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

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    char *source = (char *) v->data + index * v->baseTypeSize;
    // вы жестоки я хотел сам подумать, мы же должны иногда
    // думать тем более для max результата
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    char *position = (char *) v->data + index * v->baseTypeSize;
    memcpy(position, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "empty vector ");
        exit(1);
    }
    v->size--;
}

void pushBackV(vectorVoid *v, void *source) {
    if (isFullV(v)) {
        if (v->capacity == 0)
            reserveV(v, 1);
        else
            reserveV(v, v->capacity * 2);
    }
    setVectorValueV(v, v->size, source);
    v->size++;
}
