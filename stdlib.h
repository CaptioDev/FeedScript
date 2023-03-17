#ifndef MATH_STDLIB_H
#define MATH_STDLIB_H

#include <stdio.h>
#include <stdlib.h>

void math_exit(int status);
void math_print(const char *str);
void math_println(const char *str);
int math_read_int(void);
float math_read_float(void);

#endif /* MATH_STDLIB_H */
