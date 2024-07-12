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
#include "serveur.h"

static void init_client(client_t *client, int fd)
{
    client->fd = fd;
    client->argument = NULL;
    client->order = NULL;
    client->flags = 0;
    client->info = NULL;
    client->next = NULL;
    client->name = NULL;
    client->uuid = NULL;
    client->argument = NULL;
    client->channel_use = NULL;
    client->team_use = NULL;
    client->thread_use = NULL;
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

void new_client(client_t **head, int socket)
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
    init_client(iencli, accpt);
    add_msg(&iencli->info, 500, "Welcome in my_teams");
    loop_client(head, iencli);
}