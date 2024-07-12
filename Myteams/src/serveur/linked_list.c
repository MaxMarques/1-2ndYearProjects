/*
** EPITECH PROJECT, 2021
** linked_list
** File description:
** linked_list.c
*/

#include <stdlib.h>
#include "serveur.h"

static void loop_list(client_t **client,
client_t *node, client_t *prev)
{
    if (prev == NULL)
        *client = node->next;
    else
        prev->next = node->next;
}

void list_delete_element(client_t **client, client_t *delete)
{
    client_t *node = *client;
    client_t *prev = NULL;

    while (node != NULL) {
        if (node == delete) {
            loop_list(client, node, prev);
            free_client(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}