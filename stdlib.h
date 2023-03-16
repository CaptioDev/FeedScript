#ifndef STDLIB_H
#define STDLIB_H

#include <stdio.h>
#include <stdlib.h>

void fs_exit(int status);
void fs_print(char *str);
void fs_println(char *str);
int fs_read_int(void);
float fs_read_float(void);

#endif
