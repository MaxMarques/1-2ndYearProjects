/*
** EPITECH PROJECT, 2021
** socket_rw
** File description:
** socket_rw.c
*/

#include <stdlib.h>
#include <netinet/in.h>
#include "serveur.h"

void socket_client_read(fd_set *rfds, int socket,
client_t *client, int *max)
{
    client_t *iencli = client;

    FD_ZERO(rfds);
    FD_SET(socket, rfds);
    while (iencli != NULL) {
        if (iencli->fd > *max)
            *max = iencli->fd;
        FD_SET(iencli->fd, rfds);
        iencli = iencli->next;
    }
}

void socket_client_write(fd_set *write, client_t *client)
{
    client_t *iencli = client;

    FD_ZERO(write);

    while (iencli != NULL) {
        if (iencli->info != NULL)
            FD_SET(iencli->fd, write);
        iencli = iencli->next;
    }
}