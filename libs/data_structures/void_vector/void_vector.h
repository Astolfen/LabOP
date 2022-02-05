#ifndef INC_VOID_VECTOR_H
#define INC_VOID_VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct vectorVoid {
    void *data;             // указатель на нулевой элемент вектора
    size_t size;            // размер вектора
    size_t capacity;        // вместимость вектора
    size_t baseTypeSize;    // размер базового типа:
} vectorVoid;

// создает вектор размера n
// с базовым типом размера baseTypeSize
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

// изменяет количесво памяти выделенной
// под массив структуры v на размер newCapacity
void reserveV(vectorVoid *v, size_t newCapacity);

//освобождает память вектора v
// занятую неиспользуеммыми элементами
void shrinkToFitV(vectorVoid *v);

//удаляет элементы векторов v
// без освобождения памяти
void clearV(vectorVoid *v);

//освобождает память выделенную под вектор v
void deleteVectorV(vectorVoid *v);

#endif
