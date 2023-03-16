#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "parser.h"
#include "symbol_table.h"

typedef struct {
    symbol_table_t *symbol_table;
} interpreter_t;

void interpreter_init(interpreter_t *interpreter);
void interpreter_cleanup(interpreter_t *interpreter);
void interpreter_eval(interpreter_t *interpreter, ast_node_t *node);

#endif
