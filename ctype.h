#ifndef CTYPE_H
#define CTYPE_H

int is_alpha(char c);
int is_upper(char c);
int is_lower(char c);
int is_digit(char c);
int is_alnum(char c);
int is_whitespace(char c);
int is_punct(char c);
int is_printable(char c);
int is_hex_digit(char c);
int is_space(char c);
int is_control(char c);
int is_graph(char c);
char to_upper(char c);
char to_lower(char c);

#endif