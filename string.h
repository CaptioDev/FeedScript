#ifndef STRING_H
#define STRING_H

typedef struct {
    char *data;
    int length;
    int capacity;
} String;

String *make_string(char *data);
void free_string(String *str);
void append_string(String *dest, char *src);
void append_char(String *str, char c);
char *string_to_cstr(String *str);

#endif
