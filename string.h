#ifndef FEEDSCRIPT_STRING_H
#define FEEDSCRIPT_STRING_H

#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} String;

// Allocate a new string with the given data
String *string_create(const char *data);

// Free the memory allocated for the given string
void string_free(String *str);

// Append the source string to the destination string
void string_append(String *dest, const char *src);

// Append the given character to the string
void string_append_char(String *str, char c);

// Get a C-style string representation of the given string
const char *string_cstr(const String *str);

#endif
