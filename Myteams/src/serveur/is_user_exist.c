/*
** EPITECH PROJECT, 2021
** serveur
** File description:
** is_user_exist.c
*/

#include <stdlib.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "serveur.h"

int is_user_exist(const char *name, client_t **head)
{
    (void)head;
    FILE *fd = fopen("./database/users.csv", "r");
    char *buffer = NULL;
    size_t size = 0;
    char *tmp = NULL;

    getline(&buffer, &size, fd);

    while (getline(&buffer, &size, fd) != -1) {
        tmp = strsep(&buffer, ",\n");
        tmp = strsep(&buffer, ",\n");
        if (strcmp(tmp, name) == 0)
            return (1);
    }
    return (0);
}

static void push_back_user_status(users_t **head,
users_t *iencli)
{
    users_t *clicli = *head;

    if (clicli == NULL) {
        (*head) = iencli;
        return;
    }
    while (clicli->next != NULL)
        clicli = clicli->next;
    clicli->next = iencli;
}

void add_user_status(users_t **head, char *conversation_path,
char *name, char *uuid)
{
    users_t *iencli = malloc(sizeof(users_t));
    if (iencli == NULL)
        return;
    iencli->next = NULL;
    iencli->uuid = strdup(uuid);
    iencli->name = strdup(name);
    iencli->connected = 1;
    iencli->conversation_path = strdup(conversation_path);
    push_back_user_status(head, iencli);
}
