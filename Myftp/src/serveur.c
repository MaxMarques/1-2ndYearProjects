/*
** EPITECH PROJECT, 2021
** serveur
** File description:
** serveur.c
*/

#include <stdlib.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "my_ftp.h"

static void socket_client_read(fd_set *rfds, int socket,
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

static void socket_client_write(fd_set *write, client_t *client)
{
    client_t *iencli = client;

    FD_ZERO(write);

    while (iencli != NULL) {
        if (iencli->info != NULL)
            FD_SET(iencli->fd, write);
        iencli = iencli->next;
    }
}

static void read_buffer(client_t *client, fd_set *rfds)
{
    client_t *iencli = client;
    client_t *prev = NULL;
    char *line = malloc(sizeof(char) * SIZE_READ);

    while (iencli != NULL) {
        if (FD_ISSET(iencli->fd, rfds)) {
            int read_files = read(iencli->fd, line, SIZE_READ);
            if (read_files <= 0) {
                prev = iencli->next;
                close(iencli->fd);
                list_delete_element(&client, iencli);
                iencli = prev;
                continue;
            }
            parser_commande(iencli, line);
        }
        iencli = iencli->next;
    }
}

static void write_buffer(client_t **client, fd_set *write)
{
    client_t *iencli = *client;
    client_t *prev = NULL;

    while (iencli != NULL) {
        if (FD_ISSET(iencli->fd, write)) {
            print_info(iencli->fd, &iencli->info);
            if (iencli->quit == true) {
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

int managed_socket(int socket, char *av)
{
    client_t *client = NULL;
    fd_set rfds;
    fd_set write;
    int max = socket;

    if (listen(socket, 30) == -1) return (84);
    while (1) {
        socket_client_read(&rfds, socket, client, &max);
        socket_client_write(&write, client);
        int slc = select(max + 1, &rfds, &write, NULL, NULL);
        if (slc == -1 && errno == EINTR) continue;
        if (slc == -1) break;
        if (FD_ISSET(socket, &rfds)) new_client(&client, socket, av);
        read_buffer(client, &rfds);
        write_buffer(&client, &write);
    }
    close(socket);
    return (0);
}