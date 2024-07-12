/*
** EPITECH PROJECT, 2021
** my_free
** File description:
** my_free.c
*/

#include "mlloc.h"

mllc_t *get_block(void *ptr) {
    if (ptr == NULL)
        return NULL;
    return ((mllc_t *)((char *)ptr - sizeof(mllc_t)));
}

void free(void *ptr) {
    mllc_t *fee = NULL;

    if (ptr == NULL)
        return;
    fee = get_block(ptr);
    fee->free = true;
}