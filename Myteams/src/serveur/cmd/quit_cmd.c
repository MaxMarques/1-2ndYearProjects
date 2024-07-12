/*
** EPITECH PROJECT, 2021
** quit_cmd
** File description:
** quit_cmd.c
*/

#include <stdlib.h>
#include "serveur.h"

void quit_cmd(client_t *client, users_t **users)
{
    (void)users;
    char *str = my_strcomb("Good bye ", client->name);
    add_msg(&client->info, 300, str);
    client->flags = 0;
    client->flags |= QUIT;
}