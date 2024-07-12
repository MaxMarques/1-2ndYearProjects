/*
** EPITECH PROJECT, 2021
** noop_cmd
** File description:
** noop_cmd.c
*/

#include "my_ftp.h"

void noop_cmd(client_t *client)
{
    add_msg(&client->info, 200, "NOOP ok.");
}