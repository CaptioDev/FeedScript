#ifndef MATH_TYPES_H
#define MATH_TYPES_H

#include <stdio.h> // include stdio.h header file

// Define a complex number data type
typedef struct {
    double real;
    double imag;
} complex_t;

// Define a vector data type
typedef struct {
    double *data;
    size_t size;
} vector_t;

// Define a matrix data type
typedef struct {
    double **data;
    size_t rows;
    size_t cols;
} matrix_t;

#endif
