/*
** EPITECH PROJECT, 2021
** my_malloc
** File description:
** my_malloc.c
*/

#include "mlloc.h"

void *memory = NULL;

static mllc_t *create_space(mllc_t *last, size_t size)
{
    mllc_t *block = NULL;
    size_t s_size = AS(size + sizeof(mllc_t), 2 * getpagesize());

    block = sbrk(s_size);
    if (block == NULL)
        return (NULL);
    if (last != NULL)
        last->next = block;
    block->size = s_size - sizeof(mllc_t);
    block->next = NULL;
    block->free = false;

    return (block);
}

static mllc_t *check_free(mllc_t **last, size_t size)
{
    mllc_t *now = memory;

    while (now != NULL && !(now->free && now->size >= size)) {
        *last = now;
        now = now->next;
    }
    return (now);
}

void *malloc(size_t size) {
    mllc_t *block = NULL;
    mllc_t *last = NULL;

    size = AS(size, 16UL);
    if (size <= 0)
        return (NULL);
    if (memory != NULL) {
        last = memory;
        block = check_free(&last, size);
        if (block != NULL)
            block->free = false;
        else {
            block = create_space(last, size);
            if (block == NULL)
                return (NULL);
        }
    } else {
        block = create_space(NULL, size);
        if (block == NULL)
            return (NULL);
        memory = block;
    }
    return (block + 1);
}