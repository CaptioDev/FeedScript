#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

// Tokenizes a number in the input buffer.
static void tokenize_number(token_t **tokens, const char *buffer, size_t *pos) {
    char value[256];
    size_t i = 0;
    while (isdigit(buffer[*pos]) || buffer[*pos] == '.') {
        value[i++] = buffer[(*pos)++];
    }
    value[i] = '\0';
    add_token(tokens, TOKEN_NUMBER, value);
}

// Tokenizes an operator in the input buffer.
static void tokenize_operator(token_t **tokens, const char *buffer, size_t *pos) {
    switch (buffer[(*pos)++]) {
        case '+': add_operator_token(tokens, OPERATOR_ADD); break;
        case '-': add_operator_token(tokens, OPERATOR_SUBTRACT); break;
        case '*': add_operator_token(tokens, OPERATOR_MULTIPLY); break;
        case '/': add_operator_token(tokens, OPERATOR_DIVIDE); break;
        default: 
            printf("Unknown operator\n"); 
            exit(1);
    }
}

// Tokenizes an identifier in the input buffer.
static void tokenize_identifier(token_t **tokens, const char *buffer, size_t *pos) {
    char value[256];
    size_t i = 0;
    while (isalnum(buffer[*pos]) || buffer[*pos] == '_') {
        value[i++] = buffer[(*pos)++];
    }
    value[i] = '\0';
    add_identifier_token(tokens, value);
}

// Tokenizes the input buffer into a linked list of tokens.
token_t *lex(const char *input) {
    token_t *tokens = NULL;
    const char *buffer = input;
    size_t buffer_len = strlen(input);
    size_t buffer_pos = 0;

    while (buffer_pos < buffer_len) {
        // Skip whitespace characters.
        while (isspace(buffer[buffer_pos])) {
            buffer_pos++;
        }

        // Tokenize a number if the current character is a digit.
        if (isdigit(buffer[buffer_pos])) {
            tokenize_number(&tokens, buffer, &buffer_pos);
        }
        // Tokenize an operator if the current character is +, -, *, or /.
        else if (strchr("+-*/", buffer[buffer_pos])) {
            tokenize_operator(&tokens, buffer, &buffer_pos);
        }
        // Tokenize an identifier if the current character is a letter or underscore.
        else if (isalpha(buffer[buffer_pos]) || buffer[buffer_pos] == '_') {
            tokenize_identifier(&tokens, buffer, &buffer_pos);
        }
        // Unknown character encountered.
        else {
            printf("Unknown character: %c\n", buffer[buffer_pos]);
            exit(1);
        }
    }

    return tokens;
}
