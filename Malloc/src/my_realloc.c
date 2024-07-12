/*
** EPITECH PROJECT, 2020
** my_realloc.c
** File description:
** my_realloc
*/

#include "mlloc.h"

void *my_memcpy(void *dest, const void *src, size_t size)
{
    char *destination = dest;
    const char *source = src;

    while (size--)
        *destination++ = *source++;
    return (dest);
}

void *realloc(void *ptr, size_t size) {
    mllc_t *new = get_block(ptr);
    void *tmp = NULL;

    if (ptr == NULL)
        return (malloc(size));
    if (new->size >= size)
        return (ptr);
    tmp = malloc(size);
    if (tmp != ptr)
    new = my_memcpy(new, ptr, new->size);
    free(ptr);
    
    return (new);
}