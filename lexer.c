#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

static char *buffer;
static size_t buffer_len;
static size_t buffer_pos;

static void add_token(token_t **tokens, token_type_t type, const char *value) {
    token_t *token = (token_t *)malloc(sizeof(token_t));
    token->type = type;
    token->value = strdup(value);
    token->next = *tokens;
    *tokens = token;
}

static void add_number_token(token_t **tokens, const char *value) {
    add_token(tokens, TOKEN_NUMBER, value);
}

static void add_operator_token(token_t **tokens, operator_type_t type) {
    char value[2] = {type, 0};
    add_token(tokens, TOKEN_OPERATOR, value);
}

static void add_identifier_token(token_t **tokens, const char *value) {
    add_token(tokens, TOKEN_IDENTIFIER, value);
}

static void skip_whitespace() {
    while (isspace(buffer[buffer_pos])) {
        buffer_pos++;
    }
}

static int is_number(char c) {
    return isdigit(c) || c == '.';
}

static void tokenize_number(token_t **tokens) {
    char value[256];
    size_t i = 0;
    while (is_number(buffer[buffer_pos])) {
        value[i++] = buffer[buffer_pos++];
    }
    value[i] = '\0';
    add_number_token(tokens, value);
}

static void tokenize_operator(token_t **tokens) {
    switch (buffer[buffer_pos++]) {
        case '+': add_operator_token(tokens, OPERATOR_ADD); break;
        case '-': add_operator_token(tokens, OPERATOR_SUBTRACT); break;
        case '*': add_operator_token(tokens, OPERATOR_MULTIPLY); break;
        case '/': add_operator_token(tokens, OPERATOR_DIVIDE); break;
        default: printf("Unknown operator\n"); exit(1);
    }
}

static void tokenize_identifier(token_t **tokens) {
    char value[256];
    size_t i = 0;
    while (isalpha(buffer[buffer_pos])) {
        value[i++] = buffer[buffer_pos++];
    }
    value[i] = '\0';
    add_identifier_token(tokens, value);
}

token_t *lex(const char *input) {
    buffer = strdup(input);
    buffer_len = strlen(input);
    buffer_pos = 0;

    token_t *tokens = NULL;

    while (buffer_pos < buffer_len) {
        skip_whitespace();
        if (is_number(buffer[buffer_pos])) {
            tokenize_number(&tokens);
        } else if (strchr("+-*/", buffer[buffer_pos])) {
            tokenize_operator(&tokens);
        } else if (isalpha(buffer[buffer_pos])) {
            tokenize_identifier(&tokens);
        } else {
            printf("Unknown character: %c\n", buffer[buffer_pos]);
            exit(1);
        }
    }

    free(buffer);
    return tokens;
}
