#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>

#define MAX_TOKEN_LENGTH 100

typedef struct {
    char lexeme[MAX_TOKEN_LENGTH];
    int type;
} token;

void parse(FILE* input);
int match(token t, int type);

#endif
