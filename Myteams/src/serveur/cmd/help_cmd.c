/*
** EPITECH PROJECT, 2021
** help_cmd
** File description:
** help_cmd.c
*/

#include <stdlib.h>
#include <string.h>
#include "serveur.h"

static const char *help[] =
{
    "QUIT",
    "/LOGIN",
    "/HELP",
    "/LOGOUT",
    NULL,
};

static char *hlp[] =
{
    "quit : leave serveur",
    "/login [“user_name”] : set the user_name used by client",
    "/help : show help",
    "/logout : disconnect the client from the server",
    "/users : get the list of all users that exist on the domain",
    "/user [“user_uuid”] : get information about a user",
    "/send [“user_uuid”] [“message_body”] : send a message to a user",
    "/messages [“user_uuid”] : list all messages exchange with an user",
    "/subscribe [“team_uuid”] : subscribe to the event of a team and its \
    sub directories (enable reception of all events from a team)",
    "/subscribed ?[“team_uuid”] : list all subscribed teams or list all \
    users subscribed to a team",
    "/unsubscribe [“team_uuid”] : unsubscribe from a team",
    "/use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”] : use specify \
    a context team/channel/thread",
    "/create : based on what is being used create the sub resource (see below)",
    "/list : based on what is being used list all the sub resources \
    (see below)",
    "/info : based on what is being used list the current (see below)",
};

static void message_help(client_t *client)
{
    add_msg(&client->info, 300,
    "Help message.\n"
    "    On how to use the server or the meaning of a particular"
    "non-standard command.\n"
    "    This reply is useful only to the human user.");
}

void help_cmd(client_t *client, users_t **users)
{
    (void)users;
    if (client->argument == NULL) {
        message_help(client);
        return;
    }
    for (int i = 0; client->argument[0][i] != '\0'; i++) {
        if (client->argument[0][i]  >= 'a' &&  client->argument[0][i] <= 'z') {
            client->argument[0][i] -=  'a' - 'A';
        }
    }
    for (int i = 0; help[i] != NULL; i++) {
        if (strcmp(help[i], client->argument[0]) == 0) {
            add_msg(&client->info, 300, hlp[i]);
            return;
        }
    }
    add_msg(&client->info, 500, "Unknown command.");
}