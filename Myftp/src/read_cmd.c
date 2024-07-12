/*
** EPITECH PROJECT, 2021
** read_cmd
** File description:
** read_cmd.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_ftp.h"

static const char *commande[] =
{
    "USER",
    "PASS",
    "QUIT",
    "CWD",
    "CDUP",
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

static void(*cmd[])(client_t *client) =
{
    user_cmd,
    pass_cmd,
    quit_cmd,
    cwd_cmd,
    cdup_cmd,
    port_cmd,
    pasv_cmd,
    stor_cmd,
    retr_cmd,
    list_cmd,
    dele_cmd,
    pwd_cmd,
    help_cmd,
    noop_cmd,
};

void read_cmd(client_t *client)
{
    if (client->order == NULL)
        return;
    if (client->login == false) {
        if (strcmp(client->order, "USER") == 0)
            cmd[0](client);
        else if (strcmp(client->order, "PASS") == 0)
            cmd[1](client);
        else if (strcmp(client->order, "QUIT") == 0)
            cmd[2](client);
        else
            add_msg(&client->info, 530, "Please login with USER and PASS");
    } else {
        for (int i = 2; commande[i] != NULL; i++) {
            if (strcmp(commande[i], client->order) == 0) {
                cmd[i](client);
                return;
            }
        }
        add_msg(&client->info, 500, "Unknown command.");
    }
}