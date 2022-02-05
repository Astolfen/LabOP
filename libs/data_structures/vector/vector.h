#ifndef INC_VECTOR_H
#define INC_VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

typedef struct vector {
    int *data;          // указатель на элементы вектора
    size_t size;        // размер вектора
    size_t capacity;    // вместимость вектора
} vector;

// создает вектор размера n
vector createVector(size_t n);

// изменяет количесво памяти выделенной
// под массив структуры v на размер newCapacity
void reserve(vector *v, size_t newCapacity);

//удаляет элементы векторов v
// без освобождения памяти
void clear(vector *v);

//освобождает память вектора v
// занятую неиспользуеммыми элементами
void shrinkToFit(vector *v);

//освобождает память выделенную под вектор v
void deleteVector(vector *v);

//возвращает true если вектор является пустым
// иначе false
bool isEmpty(vector *v);

//возращает true если выделенная память
// под вектор v полностью занята иначе false
bool isFull(vector *v);

//возвращает i элемент вектора v
// (i гарантируется что принадлежит v)
int getVectorValue(vector *v, size_t i);

//добавляет элемент x в вектор v
void pushBack(vector *v, int x);

//удаляет последний элеммент вектора v
void popBack(vector *v);

//возвращает указатель на index-ный
// элемент вектора v
int *atVector(vector *v, size_t index);

//возвращает последний элемент вектора v
int *back(vector *v);

//возвращает нулевой элемент вектора v
int *front(vector *v);

#endif