#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOK_INT,
    TOK_FLOAT,
    TOK_IDENT,
    TOK_PLUS,
    TOK_MINUS,
    TOK_STAR,
    TOK_SLASH,
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_EOF
} TokenType;

typedef struct {
    TokenType type;
    char *value;
} Token;

Token *get_next_token(void);

#endif
