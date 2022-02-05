#ifndef INC_VECTOR_H
#define INC_VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct vector {
    int *data;          // указатель на элементы вектора
    size_t size;        // размер вектора
    size_t capacity;    // вместимость вектора
} vector;

// создает вектор размера n
vector createVector(size_t n);

// изменяет количесво памяти выделенной
// под массив структуры v на размер newCapcity
void reserve(vector *v, size_t newCapacity);

//удаляет элементы векторов v
// без освобождения памяти
void clear(vector *v);

//освобождает память вектора v
// занятую неиспользуеммыми элементами
void shrinkToFit(vector *v);

//освобождает память выделенную под вектор v
void deleteVector(vector *v);

#endif