/*
** EPITECH PROJECT, 2021
** client
** File description:
** client.c
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include "logging_client.h"
#include "client.h"

void logout_client(char *cmd, char *line)
{
    (void)cmd;
    char *uuid = NULL;
    char *name = NULL;
    strtok(line, " \n\r");

    uuid = strtok(NULL, " \n\r");
    name = strtok(NULL, " \n\r");

    client_event_logged_out(uuid, name);
}
