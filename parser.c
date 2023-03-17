#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

static expression_t *parse_expression(token_t **tokens);

static expression_t *parse_number(token_t **tokens) {
    expression_t *expr = (expression_t *)malloc(sizeof(expression_t));
    if (expr == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    expr->type = EXPR_NUMBER;
    expr->value = atof((*tokens)->value);
    *tokens = (*tokens)->next;
    return expr;
}

static expression_t *parse_identifier(token_t **tokens) {
    expression_t *expr = (expression_t *)malloc(sizeof(expression_t));
    if (expr == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    expr->type = EXPR_IDENTIFIER;
    expr->identifier = strdup((*tokens)->value);
    if (expr->identifier == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
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

static expression_t *parse_factor(token_t **tokens) {
    if ((*tokens)->type == TOKEN_OPERATOR && (*tokens)->value[0] == '-') {
        *tokens = (*tokens)->next;
        expression_t *factor = parse_factor(tokens);
        expression_t *expr = (expression_t *)malloc(sizeof(expression_t));
        if (expr == NULL) {
            printf("Memory allocation error\n");
            exit(1);
        }
        expr->type = EXPR_OPERATOR;
        expr->operator_type = OPERATOR_MULTIPLY;
        expr->left = factor;
        expr->right = (expression_t *)malloc(sizeof(expression_t));
        if (expr->right == NULL) {
            printf("Memory allocation error\n");
            exit(1);
        }
        expr->right->type = EXPR_NUMBER;
        expr->right->value = -1.0;
        return expr;
    } else {
        return parse_primary(tokens);
    }
}

static expression_t *parse_term(token_t **tokens) {
    expression_t *expr = parse_factor(tokens);
    while ((*tokens)->type == TOKEN_OPERATOR &&
           ((*tokens)->value[0] == '*' || (*tokens)->value[0] == '/')) {
        operator_type_t op = (*tokens)->value[0] == '*' ? OPERATOR_MULTIPLY : OPERATOR_DIVIDE;
        *tokens = (*tokens)->next;
        expression_t *right = parse_factor(tokens);
        expression_t *new_expr = (expression_t *)malloc(sizeof(expression_t));
        if (new_expr == NULL) {
            printf("Memory allocation error\n");
            exit(1);
        }
        int main() {
    char input[100];
    printf("Enter expression: ");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Error reading input\n");
        return 1;
    }
    token_t *tokens = tokenize(input);
    if (!tokens) {
        printf("Error tokenizing input\n");
        return 1;
    }
    expression_t *expr = parse_tokens(tokens);
    if (!expr) {
        printf("Error parsing expression\n");
        free_tokens(tokens);
        return 1;
    }
    printf("Parsed expression: ");
    print_expression(expr);
    printf("\n");
    free_expression(expr);
    free_tokens(tokens);
    return 0;
}
