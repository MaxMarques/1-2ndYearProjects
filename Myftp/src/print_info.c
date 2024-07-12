/*
** EPITECH PROJECT, 2021
** print_info
** File description:
** print_info.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "my_ftp.h"

void print_info(int fd, info_t **info)
{
    info_t *p = NULL;
    info_t *inf = *info;
    char *msg = NULL;

    while (inf != NULL) {
        size_t size_msg = strlen(inf->msg) + 7;
        msg = malloc(sizeof(char) * size_msg);
        snprintf(msg, size_msg, "%d %s\r\n", inf->code, inf->msg);
        write(fd, msg, strlen(msg));
        p = inf;
        inf = inf->next;
        free_info(p);
        free(msg);
    }
    *info = NULL;
}