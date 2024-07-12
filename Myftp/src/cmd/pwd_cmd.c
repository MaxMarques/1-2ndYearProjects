/*
** EPITECH PROJECT, 2021
** pwd_cmd
** File description:
** pwd_cmd.c
*/

#include "my_ftp.h"

void pwd_cmd(client_t *client)
{
    add_msg(&client->info, 257, client->cwd);
}