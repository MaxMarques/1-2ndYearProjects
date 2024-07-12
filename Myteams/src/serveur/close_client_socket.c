/*
** EPITECH PROJECT, 2021
** close_client_socket
** File description:
** close_client_socket.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "serveur.h"

void close_client_socket(client_t **client)
{
    client_t *iencli = *client;

    while (iencli != NULL) {
        close(iencli->fd);
        iencli = iencli->next;
    }
}