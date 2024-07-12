/*
** EPITECH PROJECT, 2021
** cdup_cmd
** File description:
** cdup_cmd.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my_ftp.h"

void cdup_cmd(client_t *client)
{
    //char *path = realpath("..", NULL);

    if (chdir(client->argument) == 0) {
        memset(client->cwd, '\0', PATH_MAX);
        strcat(client->cwd, client->argument);
        add_msg(&client->info, 250, "Directory successfully changed.");
        return;
    } else
        add_msg(&client->info, 550, "Failed to change directory.");
}