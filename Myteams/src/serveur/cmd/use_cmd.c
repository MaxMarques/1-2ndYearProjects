/*
** EPITECH PROJECT, 2021
** users_cmd
** File description:
** logout_cmd.c
*/

#include "serveur.h"
#include <stdio.h>
#include <string.h>

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

void use_cmd(client_t *client, users_t **users)
{
    (void)users;
    if (client->argument == NULL)
        return;
    client->team_use = NULL;
    client->channel_use = NULL;
    client->thread_use = NULL;
    if (client->argument[0]) {
        client->team_use = strdup(client->argument[0]);
        remove_char_string(client->team_use, '\"');
    } else
        return;
    if (client->argument[1]) {
        client->channel_use = strdup(client->argument[1]);
        remove_char_string(client->channel_use, '\"');
    } else
        return;
    if (client->argument[2]) {
        client->thread_use = strdup(client->argument[2]);
        remove_char_string(client->thread_use, '\"');
    }
}