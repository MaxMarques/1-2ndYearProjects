/*
** EPITECH PROJECT, 2021
** help_cmd
** File description:
** help_cmd.c
*/

#include <stdlib.h>
#include <string.h>
#include "my_ftp.h"

static const char *help[] =
{
    "USER",
    "PASS",
    "CWD",
    "CDUP",
    "QUIT",
    "PORT",
    "PASV",
    "STOR",
    "RETR",
    "LIST",
    "DELE",
    "PWD",
    "HELP",
    "NOOP",
    NULL,
};

static char *hlp[] =
{
    "USER : Specify user for authentication",
    "PASS : Specify password for authentication",
    "CWD : Change working directory",
    "CDUP : Change working directory to parent directory",
    "QUIT : Disconnection",
    "PORT : Enable ""active"" mode for data transfer",
    "PASV : Enable ""passive"" mode for data transfer",
    "STOR : Upload file from client to server",
    "RETR : Download file from server to client",
    "LIST : List files in the current working directory",
    "DELE : Delete file on the server",
    "PWD : Print working directory",
    "HELP : List available commands",
    "NOOP : Do nothing",
};

void help_cmd(client_t *client)
{
    if (client->argument == NULL) {
        add_msg(&client->info, 214,
        "Help message.\n"
        "    On how to use the server or the meaning of a particular"
        "non-standard command.\n"
        "    This reply is useful only to the human user.");
        return;
    } else {
        for (int i = 0; help[i] != NULL; i++) {
            if (strcmp(help[i], client->argument) == 0) {
                add_msg(&client->info, 214, hlp[i]);
                return;
            }
        }
    }
    add_msg(&client->info, 214,
    "Help message.\n"
    "    On how to use the server or the meaning of a particular"
    "non-standard command.\n"
    "    This reply is useful only to the human user.");
}