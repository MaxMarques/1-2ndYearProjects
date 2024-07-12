/*
** EPITECH PROJECT, 2021
** serveur
** File description:
** parse_data.c
*/

#include <stdlib.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "serveur.h"

int check_data_dir(void)
{
    struct stat st = {0};

    if (stat("./database", &st) == -1)
        return (0);
    return (1);
}

int create_data_dir(void)
{
    return (mkdir("./database", 0700));
}

int check_data_file(void)
{
    FILE *fd = fopen("./database/users.csv", "r");

    if (fd == NULL)
        return (0);
    return (1);
}

int create_csv_users(void)
{
    FILE *fd = fopen("./database/users.csv", "w");

    if (fd == NULL)
        return (0);
    fputs("\"user_uuid\",\"user_name\",\"user_conversation_path\",", fd);
    fclose(fd);
    return (1);
}