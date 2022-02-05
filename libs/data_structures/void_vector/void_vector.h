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

//возвращает true если вектор является пустым
// иначе false
bool isEmptyV(vectorVoid *v);

//возращает true если выделенная память
// под вектор v полностью занята иначе false
bool isFullV(vectorVoid *v);

//возвращает i элемент вектора v
// (i гарантируется что принадлежит v)
void getVectorValueV(vectorVoid *v, size_t index, void *destination);

//записывает на index-ый элемент вектора v значение, расположенное по
//адресу source
void setVectorValueV(vectorVoid *v, size_t index, void *source);

//удаляет последний элеммент вектора v
void popBackV(vectorVoid *v);

//добавляет элемент source в вектор v
void pushBackV(vectorVoid *v, void *source);

#endif