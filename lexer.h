#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_IDENTIFIER
} token_type_t;

typedef enum {
    OPERATOR_ADD,
    OPERATOR_SUBTRACT,
    OPERATOR_MULTIPLY,
    OPERATOR_DIVIDE
} operator_type_t;

typedef struct token {
    token_type_t type;
    char *value;
    struct token *next;
} token_t;

token_t *lex(const char *input);
void add_token(token_t **tokens, token_type_t type, const char *value);
void add_operator_token(token_t **tokens, operator_type_t type);
void add_identifier_token(token_t **tokens, const char *value);
void free_tokens(token_t *tokens);

#endif
