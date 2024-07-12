/*
** EPITECH PROJECT, 2021
** login_cmd
** File description:
** login_cmd.c
*/

#include <stdlib.h>
#include <string.h>
#include "serveur.h"
#include <unistd.h>
#include <stdio.h>
#include <logging_server.h>

static void remove_char_string(char *str, char delete)
{
    char *src = NULL;
    char *dst = NULL;

    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != delete)
            dst++;
    }
    *dst = '\0';
}

static void sep_context_one(client_t *client)
{
    char *tmp_uuid = uuid_generator();
    if (client->team_use == NULL && client->channel_use == NULL
    && client->thread_use == NULL) {
        if (client->argument[0] != NULL && client->argument[1] != NULL) {
            remove_char_string(client->argument[0], '\"');
            server_event_team_created(tmp_uuid,
            client->argument[0], client->uuid);
            return;
        }
    }
    if (client->team_use != NULL && client->channel_use == NULL
    && client->thread_use == NULL) {
        if (client->argument[0] != NULL && client->argument[1] != NULL) {
            remove_char_string(client->argument[0], '\"');
            server_event_channel_created(client->team_use,
            tmp_uuid, client->argument[0]);
            return;
        }
    }
}

static void sep_context_two(client_t *client)
{
    char *tmp_uuid = uuid_generator();
    if (client->team_use != NULL && client->channel_use != NULL
    && client->thread_use == NULL) {
        if (client->argument[0] != NULL && client->argument[1] != NULL) {
            remove_char_string(client->argument[0], '\"');
            remove_char_string(client->argument[1], '\"');
            server_event_thread_created(client->channel_use,
            tmp_uuid, client->uuid, client->argument[0], client->argument[1]);
            return;
        }
    }
    if (client->team_use != NULL && client->channel_use != NULL
    && client->thread_use != NULL) {
        if (client->argument[0] != NULL) {
            remove_char_string(client->argument[0], '\"');
            server_event_thread_new_reply(client->thread_use, client->uuid,
            client->argument[0]);
            return;
        }
    }
}

void context(client_t *client, users_t **users)
{
    (void)users;
    sep_context_one(client);
    sep_context_two(client);
}

void create_cmd(client_t *client, users_t **users)
{
    if (client->flags == LOGIN) {
        if (client->argument == NULL)
            return;
        context(client, users);
    }
}