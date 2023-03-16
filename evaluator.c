#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evaluator.h"

double evaluate_expression(expression_t *expr, environment_t *env);

double evaluate_number(expression_t *expr, environment_t *env) {
    return expr->value;
}

double evaluate_identifier(expression_t *expr, environment_t *env) {
    symbol_t *symbol = lookup_symbol(env, expr->identifier);
    if (!symbol) {
        printf("Undefined variable: %s\n", expr->identifier);
        exit(1);
    }
    return symbol->value;
}

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
            return left / right;
        default:
            printf("Unknown operator type: %d\n", expr->operator_type);
            exit(1);
    }
}

double evaluate_expression(expression_t *expr, environment_t *env) {
    switch (expr->type) {
        case EXPR_NUMBER:
            return evaluate_number(expr, env);
        case EXPR_IDENTIFIER:
            return evaluate_identifier(expr, env);
        case EXPR_OPERATOR:
            return evaluate_operator(expr, env);
        default:
            printf("Unknown expression type: %d\n", expr->type);
            exit(1);
    }
}

double evaluate(expression_t *expr, environment_t *env) {
    return evaluate_expression(expr, env);
}
