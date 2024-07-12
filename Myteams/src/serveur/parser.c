/*
** EPITECH PROJECT, 2021
** parser
** File description:
** parser.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "serveur.h"

static const char *commande[] =
{
    "QUIT",
    "/LOGIN",
    "/HELP",
    "/LOGOUT",
    "/USERS",
    "/USE",
    "/CREATE",
    NULL,
};

static void(*cmd[])(client_t *client, users_t **users) =
{
    quit_cmd,
    login_cmd,
    help_cmd,
    logout_cmd,
    users_cmd,
    use_cmd,
    create_cmd,
};

static void read_cmd(client_t *client, users_t **users)
{
    if (client->order == NULL) return;
    if (client->flags == LOGIN) {
        for (int i = 0; commande[i] != NULL; i++) {
            if (strcmp(commande[i], client->order) == 0) {
                cmd[i](client, users);
                return;
            }
        }
        add_msg(&client->info, 500, "Unknown command.");
    } else {
        for (int i = 0; commande[i] != NULL; i++) {
            if (strcmp(commande[i], client->order) == 0) {
                cmd[i](client, users);
                return;
            }
        }
        add_msg(&client->info, 500,
        "Please loggin for use my_teams (order /help for help you)");
    }
}

static void get_command(client_t *client, users_t **users, char *buffer)
{
    char *cpy = strdup(buffer);
    char *saveptr1 = NULL;
    int i = 0;
    if (client->argument != NULL) {
        free(client->argument);
        client->argument = NULL;
    }
    char *token = strtok_r(cpy, " ,\n\r", &saveptr1);
    if (token == NULL) {
        return;
    }
    client->order = strdup(token);
    for (int i = 0; client->order[i] != '\0'; i++) {
        if (client->order[i]  >= 'a' &&  client->order[i] <= 'z')
            client->order[i] -=  'a' - 'A';
    }
    for (i = 0; token != NULL; i++) {
        token = strtok_r(NULL, " ,\n\r", &saveptr1);
        if (token == NULL)
            break;
        client->argument = realloc(client->argument, (i + 2) *  sizeof(char *));
        client->argument[i] = strdup(token);
        client->argument[i + 1] = NULL;
    }
    read_cmd(client, users);
}

void parser_commande(client_t *client, users_t **users, char *buffer)
{
    int i;

    for (i = 0; buffer[i] != '\n'; i++);
    buffer[i] = '\0';
    get_command(client, users, buffer);
}