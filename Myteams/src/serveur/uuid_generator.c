/*
** EPITECH PROJECT, 2021
** serveur
** File description:
** uuid_generator.c
*/

#include <stdlib.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "serveur.h"
#include <uuid/uuid.h>

char *uuid_generator(void)
{
    uuid_t binuuid;
    uuid_generate_random(binuuid);
    char *uuid = malloc(sizeof(char)*37);
    uuid_unparse(binuuid, uuid);

    return (uuid);
}