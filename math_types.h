#ifndef MATH_TYPES_H
#define MATH_TYPES_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    double real;
    double imag;
} complex_t;

typedef struct {
    double *data;
    size_t size;
} vector_t;

typedef struct {
    double **data;
    size_t rows;
    size_t cols;
} matrix_t;

#endif
