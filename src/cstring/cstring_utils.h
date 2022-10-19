#ifndef STRING_CSTRING_H
#define STRING_CSTRING_H

#include <stddef.h>
#include <stdbool.h>

// Checks if a string contains the specified character restricted the specified length
bool cstring_utils_contains_character_restricted(char const * text, char character, size_t length);

void cstring_trim(char *str);

void cstring_reverse(char *str);

// Resolves all the escape sequences specified in a string literal and returns an int that indicates whether an excape sequence in the string were valid
int cstring_utils_resolve_escape_sequence(char * text);

#endif