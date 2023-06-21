#ifndef UTILS_H
#define UTILS_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void *my_malloc(size_t size);
bool string_is_int(char *str);
char *my_strdup(char *src);
int my_fgets(char *buf, size_t size, int fd);

#endif /* UTILS_H */
