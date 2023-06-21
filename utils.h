#ifndef UTILS_H
#define UTILS_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_malloc(size_t size);
bool string_is_int(char *str);
char *my_strdup(char *src);


#endif /* UTILS_H */
