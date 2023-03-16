#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_IDENTIFIER
} token_type_t;

typedef enum {
    OPERATOR_ADD = '+',
    OPERATOR_SUBTRACT = '-',
    OPERATOR_MULTIPLY = '*',
    OPERATOR_DIVIDE = '/'
} operator_type_t;

typedef struct token {
    token_type_t type;
    char *value;
    struct token *next;
} token_t;

token_t *lex(const char *input);

#endif
