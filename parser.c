#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

static expression_t *parse_expression(token_t **tokens);

static expression_t *parse_number(token_t **tokens) {
    expression_t *expr = (expression_t *)malloc(sizeof(expression_t));
    expr->type = EXPR_NUMBER;
    expr->value = atof((*tokens)->value);
    *tokens = (*tokens)->next;
    return expr;
}

static expression_t *parse_identifier(token_t **tokens) {
    expression_t *expr = (expression_t *)malloc(sizeof(expression_t));
    expr->type = EXPR_IDENTIFIER;
    expr->identifier = strdup((*tokens)->value);
    *tokens = (*tokens)->next;
    return expr;
}

static expression_t *parse_parenthesis(token_t **tokens) {
    *tokens = (*tokens)->next;
    expression_t *expr = parse_expression(tokens);
    if ((*tokens)->type != TOKEN_PAREN_CLOSE) {
        printf("Expected ')' in expression\n");
        exit(1);
    }
    *tokens = (*tokens)->next;
    return expr;
}

static expression_t *parse_primary(token_t **tokens) {
    if ((*tokens)->type == TOKEN_NUMBER) {
        return parse_number(tokens);
    } else if ((*tokens)->type == TOKEN_IDENTIFIER) {
        return parse_identifier(tokens);
    } else if ((*tokens)->type == TOKEN_PAREN_OPEN) {
        return parse_parenthesis(tokens);
    } else {
        printf("Unexpected token in expression\n");
        exit(1);
    }
}

static expression_t *parse_term(token_t **tokens) {
    expression_t *expr = parse_primary(tokens);
    while ((*tokens)->type == TOKEN_OPERATOR &&
           ((*tokens)->value[0] == '*' || (*tokens)->value[0] == '/')) {
        operator_type_t op = (*tokens)->value[0] == '*' ? OPERATOR_MULTIPLY : OPERATOR_DIVIDE;
        *tokens = (*tokens)->next;
        expression_t *right = parse_primary(tokens);
        expression_t *new_expr = (expression_t *)malloc(sizeof(expression_t));
        new_expr->type = EXPR_OPERATOR;
        new_expr->operator_type = op;
        new_expr->left = expr;
        new_expr->right = right;
        expr = new_expr;
    }
    return expr;
}

static expression_t *parse_expression(token_t **tokens) {
    expression_t *expr = parse_term(tokens);
    while ((*tokens)->type == TOKEN_OPERATOR &&
           ((*tokens)->value[0] == '+' || (*tokens)->value[0] == '-')) {
        operator_type_t op = (*tokens)->value[0] == '+' ? OPERATOR_ADD : OPERATOR_SUBTRACT;
        *tokens = (*tokens)->next;
        expression_t *right = parse_term(tokens);
        expression_t *new_expr = (expression_t *)malloc(sizeof(expression_t));
        new_expr->type = EXPR_OPERATOR;
        new_expr->operator_type = op;
        new_expr->left = expr;
        new_expr->right = right;
        expr = new_expr;
    }
    return expr;
}

expression_t *parse(token_t *tokens) {
    return parse_expression(&tokens);
}
