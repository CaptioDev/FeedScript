#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

static expression_t *parse_factor(token_t **tokens) {
    if ((*tokens)->type == TOKEN_OPERATOR && (*tokens)->value[0] == '-') {
        *tokens = (*tokens)->next;
        expression_t *factor = parse_factor(tokens);
        expression_t *expr = (expression_t *)malloc(sizeof(expression_t));
        expr->type = EXPR_OPERATOR;
        expr->operator_type = OPERATOR_MULTIPLY;
        expr->left = factor;
        expr->right = (expression_t *)malloc(sizeof(expression_t));
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

expression_t *parse_tokens(token_t *tokens) {
return parse_expression(&tokens);
}

void free_expression(expression_t *expr) {
if (expr == NULL) {
return;
}
free_expression(expr->left);
free_expression(expr->right);
free(expr->identifier);
free(expr);
}

void print_expression(expression_t *expr) {
if (expr->type == EXPR_NUMBER) {
printf("%g", expr->value);
} else if (expr->type == EXPR_IDENTIFIER) {
printf("%s", expr->identifier);
} else if (expr->type == EXPR_OPERATOR) {
printf("(");
print_expression(expr->left);
switch (expr->operator_type) {
case OPERATOR_ADD:
printf(" + ");
break;
case OPERATOR_SUBTRACT:
printf(" - ");
break;
case OPERATOR_MULTIPLY:
printf(" * ");
break;
case OPERATOR_DIVIDE:
printf(" / ");
break;
}
print_expression(expr->right);
printf(")");
}
}

int main() {
char input[100];
printf("Enter expression: ");
fgets(input, 100, stdin);
token_t *tokens = tokenize(input);
expression_t *expr = parse_tokens(tokens);
printf("Parsed expression: ");
print_expression(expr);
printf("\n");
free_expression(expr);
free_tokens(tokens);
return 0;
}
