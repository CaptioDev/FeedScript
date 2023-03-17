#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdbool.h>

#define MAX_IDENTIFIER_LENGTH 32
#define MAX_VALUE_LENGTH 32

typedef enum {
    TYPE_INT,
    TYPE_DOUBLE,
    TYPE_STRING,
    TYPE_BOOL,
    TYPE_VOID
} DataType;

typedef struct {
    DataType type;
    char value[MAX_VALUE_LENGTH];
} SymbolValue;

typedef struct {
    char name[MAX_IDENTIFIER_LENGTH];
    SymbolValue value;
    bool is_constant;
} Symbol;

void symbol_table_init();
bool symbol_table_add(char *name, DataType type, const char *value, bool is_constant);
bool symbol_table_update(char *name, const char *value);
bool symbol_table_get(char *name, Symbol *symbol);
bool symbol_table_delete(char *name);

#endif
