/*
** EPITECH PROJECT, 2021
** dele_cmd
** File description:
** dele_cmd.c
*/

#include <stdio.h>
#include "my_ftp.h"

void dele_cmd(client_t *client)
{
    if (remove(client->argument) == 0)
        add_msg(&client->info, 250, "Delete file on the server.");
    else
        add_msg(&client->info, 550, "Permission denied.");
}