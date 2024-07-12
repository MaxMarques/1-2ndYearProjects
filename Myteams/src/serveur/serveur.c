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
#include <signal.h>
#include "serveur.h"

static volatile bool sig = true;

static void update_var(int i)
{
    (void)i;
    sig = false;
}

static void signal_action(void)
{
    signal(SIGINT, update_var);
}

int managed_socket_serveur(int socket)
{
    client_t *client = NULL;
    users_t *users = NULL;
    fd_set rfds, write;
    int max = socket;
    signal_action();
    get_users(&users);
    if (listen(socket, 0) == -1) return (84);
    while (sig) {
        socket_client_read(&rfds, socket, client, &max);
        socket_client_write(&write, client);
        int slc = select(max + 1, &rfds, &write, NULL, NULL);
        if (slc == -1 && errno == EINTR) continue;
        if (slc == -1) break;
        if (FD_ISSET(socket, &rfds)) new_client(&client, socket);
        read_buffer(&client, &users, &rfds);
        write_buffer(&client, &write);
    }
    close_client_socket(&client);
    close(socket);
    return (0);
}