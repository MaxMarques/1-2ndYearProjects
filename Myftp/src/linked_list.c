/*
** EPITECH PROJECT, 2021
** linked_list
** File description:
** linked_list.c
*/

#include <stdlib.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "my_ftp.h"

void list_delete_element(client_t **client, client_t *delete)
{
    client_t *node = *client;
    client_t *prev = NULL;

    while (node != NULL) {
        if (node == delete) {
            if (prev == NULL)
                *client = node->next;
            else
                prev->next = node->next;
            free_client(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}