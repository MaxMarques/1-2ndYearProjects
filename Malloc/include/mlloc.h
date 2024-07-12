/*
** EPITECH PROJECT, 2021
** mlloc
** File description:
** mlloc.h
*/

#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>

#ifndef _MLLOC_
#define _MLLOC_

#define AS(sizeToAlign, PowerOfTwo) (((sizeToAlign) + (PowerOfTwo) - 1) & ~((PowerOfTwo) - 1))

typedef struct mllc
{
    size_t size;
    struct mllc *next;
    bool free;
} mllc_t;

void *malloc(size_t size);
void *my_memcpy(void *dest, const void *src, size_t size);
void *realloc(void *ptr, size_t size);
mllc_t *get_block(void *ptr);
void free(void *ptr);
void *my_memset(char *s, int c, int n);
void *calloc(size_t nmemb, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif