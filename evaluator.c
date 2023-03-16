#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evaluator.h"

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

// Evaluates a function call expression.
double evaluate_function_call(expression_t *expr, environment_t *env) {
    // Look up the function symbol in the environment
    symbol_t *symbol = lookup_symbol(env, expr->identifier);
    if (!symbol) {
        printf("Undefined function: %s\n", expr->identifier);
        exit(1);
    }
    
    // Check that the symbol is a function
    if (symbol->type != SYMBOL_FUNCTION) {
        printf("%s is not a function\n", expr->identifier);
        exit(1);
    }
    
    // Check that the number of arguments is correct
    if (symbol->arity != expr->num_args) {
        printf("Wrong number of arguments to function %s (expected %d, got %d)\n",
               expr->identifier, symbol->arity, expr->num_args);
        exit(1);
    }
    
    // Evaluate the arguments
    double *arg_values = (double*) malloc(sizeof(double) * expr->num_args);
    for (int i = 0; i < expr->num_args; i++) {
        arg_values[i] = evaluate_expression(expr->args[i], env);
    }
    
    // Call the function with the argument values
    double result = symbol->func(arg_values);
    
    // Free the argument values
    free(arg_values);
    
    return result;
}

// Evaluates an expression.
double evaluate_expression(expression_t *expr, environment_t *env) {
    switch (expr->type) {
        case EXPR_NUMBER:
            return evaluate_number(expr, env);
        case EXPR_IDENTIFIER:
            return evaluate_identifier(expr, env);
        case EXPR_OPERATOR:
            return evaluate_operator(expr, env);
        case EXPR_FUNCTION_CALL:
            return evaluate_function_call(expr, env);
        default:
            printf("Unknown expression type: %d\n", expr->type);
            exit(1);
    }
}

// Evaluates an expression and returns the result.
double evaluate(expression_t *expr, environment_t *env) {
    return evaluate_expression(expr, env);
}
