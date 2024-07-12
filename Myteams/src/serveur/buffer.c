/*
** EPITECH PROJECT, 2021
** buffer
** File description:
** buffer.c
*/

#include <stdlib.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "serveur.h"

void read_buffer(client_t **client, users_t **users, fd_set *rfds)
{
    client_t *iencli = *client;
    client_t *prev = NULL;
    char *line = malloc(sizeof(char) * SIZE_READ);

    while (iencli != NULL) {
        if (FD_ISSET(iencli->fd, rfds)) {
            int read_files = read(iencli->fd, line, SIZE_READ);
            if (read_files <= 0) {
                prev = iencli->next;
                close(iencli->fd);
                list_delete_element(client, iencli);
                iencli = prev;
                continue;
            }
            parser_commande(iencli, users, line);

        }
        iencli = iencli->next;
    }

}

void write_buffer(client_t **client, fd_set *write)
{
    client_t *iencli = *client;
    client_t *prev = NULL;

    while (iencli != NULL) {
        if (FD_ISSET(iencli->fd, write)) {
            print_info(iencli->fd, &iencli->info);
            if (iencli->flags == QUIT) {
                prev = iencli->next;
                close(iencli->fd);
                list_delete_element(client, iencli);
                iencli = prev;
                continue;
            }
        }
        iencli = iencli->next;
    }
}