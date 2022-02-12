#ifndef INC_MATRIX_H
#define INC_MATRIX_H

#include <malloc.h>

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
/// \param nRows number of Rows
/// \param nCols number of Cols
/// \return pointer to an array of pointers to arrays
matrix getMemMatrix(int nRows, int nCols);

/// Allocated memory for an array of matrices of size nRows, nCols consisting of nMatrices
/// \param nMatrices number of Matrix
/// \param nRows number of Rows
/// \param nCols number of Cols
/// \return pointer to an array Matrix
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

/// Frees up memory occupied by a matrix
/// \param m structure matrix
void freeMemMatrix(matrix m);

/// Frees up memory occupied by a array of matrices consisting of nMatrices
/// \param ms pointer to an array of matrices
/// \param nMatrices size of array ms
void freeMemMatrices(matrix *ms, int nMatrices);

#endif