#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evaluator.h"

// Creates a new environment with no parent environment.
environment_t* create_environment() {
    environment_t *env = (environment_t*) malloc(sizeof(environment_t));
    env->parent = NULL;
    env->num_symbols = 0;
    return env;
}

// Looks up a symbol in the environment and its parent environments.
symbol_t* lookup_symbol(environment_t *env, const char *identifier) {
    while (env != NULL) {
        for (int i = 0; i < env->num_symbols; i++) {
            if (strcmp(env->symbols[i].identifier, identifier) == 0) {
                return &env->symbols[i];
            }
        }
        env = env->parent;
    }
    return NULL;
}

// Adds a symbol to the environment.
void add_symbol(environment_t *env, const char *identifier, double value) {
    if (env->num_symbols == MAX_SYMBOLS) {
        printf("Error: too many symbols\n");
        exit(1);
    }
    symbol_t *symbol = &env->symbols[env->num_symbols++];
    symbol->type = SYMBOL_VARIABLE;
    symbol->identifier = (char*) malloc(sizeof(char) * (strlen(identifier) + 1));
    strcpy(symbol->identifier, identifier);
    symbol->value = value;
}

// Adds a function symbol to the environment.
void add_function(environment_t *env, const char *identifier, int arity, double (*func)(double*)) {
    if (env->num_symbols == MAX_SYMBOLS) {
        printf("Error: too many symbols\n");
        exit(1);
    }
    symbol_t *symbol = &env->symbols[env->num_symbols++];
    symbol->type = SYMBOL_FUNCTION;
    symbol->identifier = (char*) malloc(sizeof(char) * (strlen(identifier) + 1));
    strcpy(symbol->identifier, identifier);
    symbol->arity = arity;
    symbol->func = func;
}

// Deletes an environment and all its symbols.
void delete_environment(environment_t *env) {
    for (int i = 0; i < env->num_symbols; i++) {
        free(env->symbols[i].identifier);
    }
    free(env);
}

// Evaluates a number expression.
double evaluate_number(expression_t *expr, environment_t *env) {
    return expr->value;
}

// Evaluates an identifier expression.
double evaluate_identifier(expression_t *expr, environment_t *env) {
    symbol_t *symbol = lookup_symbol(env, expr->identifier);
    if (!symbol) {
        printf("Undefined variable: %s\n", expr->identifier);
        exit(1);
    }
    return symbol->value;
}

// Evaluates an operator expression.
double evaluate_operator(expression_t *expr, environment_t *env) {
    double left = evaluate_expression(expr->left, env);
    double right = evaluate_expression(expr->right, env);
    switch (expr->operator_type) {
        case OPERATOR_ADD:
            return left + right;
        case OPERATOR_SUBTRACT:
            return left - right;
        case OPERATOR_MULTIPLY:
            return left * right;
        case OPERATOR_DIVIDE:
            if (right == 0.0) {
                printf("Division by zero.\n");
                exit(1);
            }
            return left / right;
        default:
            printf("Unknown operator type: %d\n", expr->operator_type);
            exit(1);
    }
}

// Looks up a symbol in an environment.
symbol_t *lookup_symbol(environment_t *env, const char *identifier) {
for (int i = env->num_symbols - 1; i >= 0; i--) {
if (strcmp(env->symbols[i].identifier, identifier) == 0) {
return &env->symbols[i];
}
}
return NULL;
}

// Adds a symbol to an environment.
void add_symbol(environment_t *env, const char *identifier, symbol_type_t type, double value) {
if (env->num_symbols >= MAX_SYMBOLS) {
printf("Too many symbols.\n");
exit(1);
}
symbol_t *symbol = &env->symbols[env->num_symbols++];
symbol->identifier = strdup(identifier);
symbol->type = type;
symbol->value = value;
}

// Adds a function symbol to an environment.
void add_function(environment_t *env, const char *identifier, int arity, function_t func) {
if (env->num_symbols >= MAX_SYMBOLS) {
printf("Too many symbols.\n");
exit(1);
}
symbol_t *symbol = &env->symbols[env->num_symbols++];
symbol->identifier = strdup(identifier);
symbol->type = SYMBOL_FUNCTION;
symbol->arity = arity;
symbol->func = func;
}

// Creates a new environment.
environment_t *create_environment() {
environment_t env = (environment_t) malloc(sizeof(environment_t));
env->num_symbols = 0;
return env;
}

// Destroys an environment.
void destroy_environment(environment_t *env) {
for (int i = 0; i < env->num_symbols; i++) {
free(env->symbols[i].identifier);
}
free(env);
}
