/*
** EPITECH PROJECT, 2021
** pass_cmd
** File description:
** pass_cmd.c
*/

#include <string.h>
#include "my_ftp.h"

static void gest_argument(client_t *client)
{
    if (client->argument == NULL) {
        add_msg(&client->info, 530, "Login incorrect.");
        return;
    }
    if ((strcmp(client->argument, "") == 0) && client->valide == true) {
            client->pswd = true;
            client->valide = false;
            client->user = false;
            add_msg(&client->info, 230, "Login successful.");
            client->login = true;
    } else {
        add_msg(&client->info, 530, "Login incorrect.");
    }
}

void pass_cmd(client_t *client)
{
    if (client->user == false) {
        add_msg(&client->info, 503, "Login with USER first.");
        return;
    } else
        gest_argument(client);
}