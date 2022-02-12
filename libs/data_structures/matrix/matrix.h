#ifndef INC_MATRIX_H
#define INC_MATRIX_H

#include <stdio.h>
#include <malloc.h>
#include "../../algorithms/algorithm.h"

typedef struct matrix {
    int **values;   //элементы матрицы
    int nRows;      //количество рядов
    int nCols;      //количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

/// Allocates memory for the matrix
/// \param nRows volume of Rows
/// \param nCols volume of Cols
/// \return pointer to an array of pointers to arrays
matrix getMemMatrix(int nRows, int nCols);

/// Allocated memory for an array of matrices of size nRows, nCols consisting of nMatrices
/// \param nMatrices size of end array
/// \param nRows volume of Rows
/// \param nCols volume of Cols
/// \return pointer to an array Matrix
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

/// Frees up memory occupied by a matrix
/// \param m structure matrix
void freeMemMatrix(matrix m);

/// Frees up memory occupied by a array of matrices consisting of nMatrices
/// \param ms pointer to an array of matrices
/// \param nMatrices size of array ms
void freeMemMatrices(matrix *ms, int nMatrices);

/// Input matrix m
/// \param m structure matrix
void inputMatrix(matrix m);

/// Input array of matrices ms
/// \param ms pointer to an array of matrices
/// \param nMatrices size of array ms
void inputMatrices(matrix *ms, int nMatrices);

/// Output matrix m
/// \param m structure matrix
void outputMatrix(matrix m);

/// Output array of matrices ms
/// \param ms pointer to an array of matrices
/// \param nMatrices size of array ms
void outputMatrices(matrix *ms, int nMatrices);

/// Exchange of rows with numbers i1 and i2 in the matrix m
/// \param m structure matrix
/// \param i1 rows number
/// \param i2 rows number
void swapRows(matrix m, int i1, int i2);

/// Exchange of columns with numbers j1 and j2 in the matrix m
/// \param m structure matrix
/// \param j1 colum number
/// \param j2 colum number
void swapColumns(matrix m, int j1, int j2);

#endif