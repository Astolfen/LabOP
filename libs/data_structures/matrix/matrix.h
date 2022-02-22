#ifndef INC_MATRIX_H
#define INC_MATRIX_H

#include "../../algorithms/algorithm.h"
#include <memory.h>

typedef struct matrix {
    int **values;   //элементы матрицы
    int nRows;      //количество рядов
    int nCols;      //количество столбцов
} matrix;

typedef struct matrixf {
    float **values;   //элементы матрицы
    int nRows;      //количество рядов
    int nCols;      //количество столбцов
} matrixf;

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
/// \param i1 rows index
/// \param i2 rows index
void swapRows(matrix m, int i1, int i2);

/// Exchange of columns with numbers j1 and j2 in the matrix m
/// \param m structure matrix
/// \param j1 colum index
/// \param j2 colum index
void swapColumns(matrix m, int j1, int j2);

/// Sorting by inserting rows of the matrix m by non-growth by criterion criteria
/// \param m structure matrix
/// \param criteria function of array processing
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));

/// Sorting by inserting columns of the matrix m by non-growth by criterion
/// \param m structure matrix
/// \param criteria function of array processing
void choiceSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int));

/// Checks whether the matrix m is square
/// \param m structure matrix
/// \return true or false
bool isSquareMatrix(matrix m);

/// Checks whether the matrix m1 and matrix m2 is equal
/// \param m1 structure matrix
/// \param m2 structure matrix
/// \return true or false
bool twoMatricesEqual(matrix m1, matrix m2);

/// Checks whether the matrix m is identity matrix
/// \param m structure matrix
/// \return true or false
bool isEMatrix(matrix m);

/// Checks whether the matrix m is symmetric
/// \param m structure matrix
/// \return true or false
bool isSymmetricMatrix(matrix m);

/// Transposes a square matrix m
/// \param m structure matrix
void transposeSquareMatrix(matrix m);

/// Finds the minimum in the matrix m
/// \param m structure matrix
/// \return structure position
position getMinValuePos(matrix m);

/// Finds the maximum in the matrix m
/// \param m structure matrix
/// \return structure position
position getMaxValuePos(matrix m);

//for test
matrix createMatrixFromArray(const int *a, int nRows, int nCols);

//for test
matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices, int nRows, int nCols);

/// Allocates memory for the matrix
/// \param nRows volume of Rows
/// \param nCols volume of Cols
/// \return pointer to an array of pointers to arrays
matrixf getMemMatrixF(int nRows, int nCols);

/// Allocated memory for an array of matrices of size nRows, nCols consisting of nMatrices
/// \param nMatrices size of end array
/// \param nRows volume of Rows
/// \param nCols volume of Cols
/// \return pointer to an array Matrix
matrixf *getMemArrayOfMatricesF(int nMatrices, int nRows, int nCols);

/// Frees up memory occupied by a matrix
/// \param m structure matrixf
void freeMemMatrixF(matrixf m);

/// Frees up memory occupied by a array of matrices consisting of nMatrices
/// \param ms pointer to an array of matrices
/// \param nMatrices size of array ms
void freeMemMatricesF(matrixf *ms, int nMatrices);

/// Input matrix m
/// \param m structure matrixf
void inputMatrixF(matrixf m);

/// Input array of matrices ms
/// \param ms pointer to an array of matrices
/// \param nMatrices size of array ms
void inputMatricesF(matrixf *ms, int nMatrices);

/// Output matrix m
/// \param m structure matrixf
void outputMatrixF(matrixf m);

/// Output array of matrices ms
/// \param ms pointer to an array of matrices
/// \param nMatrices size of array ms
void outputMatricesF(matrixf *ms, int nMatrices);

#endif