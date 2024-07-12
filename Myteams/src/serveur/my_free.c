/*
** EPITECH PROJECT, 2021
** my_free
** File description:
** my_free.c
*/

#include <stdlib.h>
#include "serveur.h"

void free_info(info_t *info)
{
    free(info->msg);
    free(info);
}

void free_client(client_t *client)
{
    info_t *ptr = client->info;
    info_t *prev = client->info;

    free(client->name);
    free(client->argument);
    free(client->order);
    while (ptr != NULL) {
        prev = ptr->next;
        free_info(ptr);
        ptr = prev;
    }
    free(client->info);
    free(client);
}