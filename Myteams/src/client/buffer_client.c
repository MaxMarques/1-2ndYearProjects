/*
** EPITECH PROJECT, 2021
** buffer_client
** File description:
** buffer_client.c
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include "logging_client.h"
#include "client.h"

static const char *commande[] =
{
    "/LOGIN",
    "/LOGOUT",
    "/USERS",
    NULL,
};

static void(*cmd[])(char *cmd, char *line) =
{
        login_client,
        logout_client,
        users_client,
};

void get_cmd(char *buffer, client_t *client)
{
    if (client->last_cmd == NULL || buffer == NULL)
        return;
    for (int i = 0; client->last_cmd[i] != '\0'; i++) {
        if (client->last_cmd[i]  >= 'a' &&  client->last_cmd[i] <= 'z') {
            client->last_cmd[i] -=  'a' - 'A';
        }
        if (client->last_cmd[i] == ' ')
            break;
    }
    for (int i = 0; commande[i] != NULL; i++) {
        if (strcmp(client->last_cmd, commande[i]) == 0) {
            cmd[i](client->last_cmd, buffer);
            return;
        }
    }

}