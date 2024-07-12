/*
** EPITECH PROJECT, 2021
** my_calloc
** File description:
** my_calloc.c
*/

#include "mlloc.h"

void *my_memset(char *s, int c, int n)
{
    for (int i = 0; s && i < n; i++)
        s[i] = c;
    return (s);
}

void *calloc(size_t nmemb, size_t size) {
    void *block = malloc(nmemb * size);

    if (block != NULL)
        my_memset(block, 0, nmemb * size);
    return (block);
}