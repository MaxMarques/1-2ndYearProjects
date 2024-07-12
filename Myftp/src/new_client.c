/*
** EPITECH PROJECT, 2021
** new_client
** File description:
** new_client.c
*/

#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>
#include "my_ftp.h"

static void path(client_t *client, char *av)
{
    char *pipe = malloc(sizeof(char) * 20);

    pipe[0] = '/';
    if (av[0] == '/')
        strcat(client->cwd, av);
    else if (av[0] == '.') {
        strcat(client->cwd, &av[1]);
    }
    else {
        strcat(pipe, av);
        strcat(client->cwd, pipe);
    }
}

static void init_client(client_t *client, int fd, char *av)
{
    client->fd = fd;
    memset(client->cwd, '\0', PATH_MAX);
    client->info = NULL;
    client->argument = NULL;
    client->order = NULL;
    client->next = NULL;
    client->quit = false;
    client->login = false;
    client->user = false;
    client->pswd = false;
    client->valide = false;
    path(client, av);
}

static void loop_client(client_t **head, client_t *iencli)
{
    client_t *clicli = *head;

    if (clicli == NULL) {
        *head = iencli;
        return;
    }
    while (clicli->next != NULL)
        clicli = clicli->next;
    clicli->next = iencli;
}

void new_client(client_t **head, int socket, char *av)
{
    struct sockaddr_in sockaddr;
    socklen_t addrlen = sizeof(sockaddr);
    client_t *iencli = NULL;
    int accpt = accept(socket, (struct sockaddr *) &sockaddr, &addrlen);
    if (accpt == -1)
        return;
    iencli = malloc(sizeof(client_t));
    if (iencli == NULL)
        return;
    init_client(iencli, accpt, av);
    add_msg(&iencli->info, 220, "Service ready for new user.");
    loop_client(head, iencli);
}