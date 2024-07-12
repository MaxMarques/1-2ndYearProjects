/*
** EPITECH PROJECT, 2021
** my_reallocarray
** File description:
** my_reallocarray.c
*/

#include "mlloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if ((SIZE_MAX / nmemb) < size)
        return (NULL);

    return (realloc(ptr, size * nmemb));
}