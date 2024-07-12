/*
** EPITECH PROJECT, 2021
** quit_cmd
** File description:
** quit_cmd.c
*/

#include <stdlib.h>
#include "my_ftp.h"

void quit_cmd(client_t *client)
{
    add_msg(&client->info, 221,
    "Service closing control connection.\n"
    "    Logged out if appropriate.");
    client->quit = true;
}