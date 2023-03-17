#ifndef MATH_STDIO_H
#define MATH_STDIO_H

#include <stdio.h>
#include "math_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Function to print a complex number
void math_fprintf_complex(FILE *stream, const char *format, complex_t c);

// Function to read a complex number
void math_scanf_complex(const char *format, complex_t *c);

// Function to print a vector
void math_fprintf_vector(FILE *stream, const char *format, vector_t v);

// Function to read a vector
void math_scanf_vector(const char *format, vector_t *v);

// Function to print a matrix
void math_fprintf_matrix(FILE *stream, const char *format, matrix_t m);

// Function to read a matrix
void math_scanf_matrix(const char *format, matrix_t *m);

#ifdef __cplusplus
}
#endif

#endif /* MATH_STDIO_H */