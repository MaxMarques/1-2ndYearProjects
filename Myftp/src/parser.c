/*
** EPITECH PROJECT, 2021
** parser
** File description:
** parser.c
*/

#include <stdlib.h>
#include <string.h>
#include "my_ftp.h"

void parser_commande(client_t *client, char *buffer)
{
    char *parser = NULL;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i]  >= 'a' &&  buffer[i] <= 'z')
            buffer[i] -=  'a' - 'A';
    }
    parser = strtok(buffer, "\r\n");
    client->order = strsep(&parser, " ");
    client->argument = parser;
    read_cmd(client);
}