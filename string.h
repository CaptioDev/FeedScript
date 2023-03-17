#ifndef FEEDSCRIPT_STRING_H
#define FEEDSCRIPT_STRING_H

#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} String;

/**
 * Allocate a new string with the given data.
 *
 * @param data The initial data for the string.
 * @return The new string, or NULL if memory allocation failed.
 */
String *string_create(const char *data);

/**
 * Free the memory allocated for the given string.
 *
 * @param str The string to free.
 */
void string_free(String *str);

/**
 * Append the source string to the destination string.
 *
 * @param dest The destination string.
 * @param src The source string to append.
 */
void string_append(String *dest, const char *src);

/**
 * Append the given character to the string.
 *
 * @param str The string to append to.
 * @param c The character to append.
 */
void string_append_char(String *str, const char c);

/**
 * Get a C-style string representation of the given string.
 *
 * @param str The string to get the representation of.
 * @return A C-style string representing the given string.
 */
const char *string_cstr(const String *str);

#endif
