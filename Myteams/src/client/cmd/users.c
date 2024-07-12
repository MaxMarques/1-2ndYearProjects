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

void users_client(char *cmd, char *line)
{
    (void)cmd;
    if (line != NULL)
        printf("%s\n", line);
}