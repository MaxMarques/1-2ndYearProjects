/*
** EPITECH PROJECT, 2021
** user_cmd
** File description:
** user_cmd.c
*/

#include <string.h>
#include "my_ftp.h"

void user_cmd(client_t *client)
{
    if (client->argument == NULL) {
        add_msg(&client->info, 530, "Permission denied.");
        return;
    }
    for (int i = 1; client->argument[i]; i++) {
        if (client->argument[i]  >= 'A' &&  client->argument[i] <= 'Z')
            client->argument[i] += 'a' - 'A';
    }
    client->user = true;
    if (strcmp(client->argument, "Anonymous") == 0)
        client->valide = true;
    add_msg(&client->info, 331, "Please specify the password.");
}