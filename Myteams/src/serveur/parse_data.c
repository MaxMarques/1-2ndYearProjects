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
#include "serveur.h"

char *extract_uuid(char **buffer)
{
    char *uuid = strsep(buffer, ",\n");
    return (uuid);
}

char *extract_name(char **buffer)
{
    char *name = strsep(buffer, ",\n");
    return (name);
}

char *extract_conv_path(char **buffer)
{
    char *path = strsep(buffer, ",\n");
    return (path);
}