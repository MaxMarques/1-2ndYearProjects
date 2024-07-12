/*
** EPITECH PROJECT, 2021
** serveur
** File description:
** parse_clients.c
*/

#include <stdlib.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "serveur.h"
#include <logging_server.h>

static void push_back_user(users_t **head, users_t *iencli)
{
    users_t *clicli = *head;

    if (clicli == NULL) {
        *head = iencli;
        return;
    }
    while (clicli->next != NULL)
        clicli = clicli->next;
    clicli->next = iencli;
}

static void init_user(users_t *client,
char *conversation_path, char *name, char *uuid)
{
    client->next = NULL;
    client->uuid = strdup(uuid);
    client->name = strdup(name);
    client->connected = 0;
    client->conversation_path = strdup(conversation_path);
    server_event_user_loaded(client->uuid, client->name);
}

void add_user(users_t **head, char *conversation_path, char *name, char *uuid)
{
    users_t *iencli = malloc(sizeof(users_t));
    if (iencli == NULL)
        return;
    init_user(iencli, conversation_path, name, uuid);
    push_back_user(head, iencli);
}

void parse_data(users_t **head, char *buffer)
{
    char *(*extract_uuid_ptr)(char **) = &extract_uuid;
    char *(*extract_name_ptr)(char **) = &extract_name;
    char *(*extract_conversation_path_ptr)(char **) = &extract_conv_path;

    add_user(head, (*extract_conversation_path_ptr)(&buffer),
    (*extract_name_ptr)(&buffer), (*extract_uuid_ptr)(&buffer));
}

int get_existing_users(users_t **head)
{
    FILE *fd = fopen("./database/users.csv", "r");
    char *buffer = NULL;
    size_t size = 0;

    if (!fd)
        return (0);
    getline(&buffer, &size, fd);
    while (getline(&buffer, &size, fd) > 0) {
        parse_data(head, buffer);
    }
    return (1);
}