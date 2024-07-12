/*
** EPITECH PROJECT, 2021
** get_users
** File description:
** get_users.c
*/

#include <stdlib.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "serveur.h"
#include <logging_server.h>

int get_users(users_t **head)
{
    if (!check_data_dir()) {
        create_data_dir();
        create_csv_users();
        return (2);
    }
    if (!check_data_file()) {
        create_csv_users();
        return (2);
    }
    if (!get_existing_users(head))
        return (0);
    return (1);
}