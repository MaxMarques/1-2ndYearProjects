/*
** EPITECH PROJECT, 2021
** logout_cmd
** File description:
** logout_cmd.c
*/

#include "serveur.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <uuid/uuid.h>
#include <stdbool.h>
#include <logging_server.h>

static void disconect_user(char *uuid, users_t **users)
{
    users_t *head = (*users);

    while (head != NULL) {
        if (strcmp(uuid, head->uuid) == 0)
            head->connected = 0;
        head = head->next;
    }
}

void logout_cmd(client_t *client, users_t **users)
{
    (void)users;
    if (client->flags == LOGIN) {
        char *str = my_strcomb(client->uuid, " ");
        str = my_strcomb(str, client->name);
        add_msg(&client->info, 300, str);
        client->flags = 0;
        server_event_user_logged_out(client->uuid);
        disconect_user(client->uuid, users);
    }
}