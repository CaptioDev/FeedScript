#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "interpreter.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *input = (char *)malloc(size + 1);
    fread(input, 1, size, fp);
    input[size] = '\0';

    fclose(fp);

    token_t *tokens = tokenize(input);
    expression_t *expr = parse(tokens);
    value_t result = interpret_expression(expr);

    printf("%f\n", result);

    free(input);
    free_tokens(tokens);
    free_expression(expr);

    return 0;
}
