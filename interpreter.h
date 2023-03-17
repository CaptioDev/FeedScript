#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "parser.h"
#include "symbol_table.h"

// Define the symbol_table_t type
struct symbol_table {
    // PUT IN TABLE STRUCT FIELD WITH MATTHEW
};

// Define the ast_node_t type
struct ast_node {
    // PUT IN TABLE STRUCT FIELD WITH MATTHEW
};

// interpreter.h
typedef struct token {
    char* value;
    int type;
} token_t;

token_t* tokenize(char* input);

typedef struct {
    symbol_table_t *symbol_table;
} interpreter_t;

void interpreter_init(interpreter_t *interpreter);
void interpreter_cleanup(interpreter_t *interpreter);
void interpreter_eval(interpreter_t *interpreter, ast_node_t *node);

#endif
