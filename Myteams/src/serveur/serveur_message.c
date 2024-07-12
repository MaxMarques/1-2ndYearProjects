/*
** EPITECH PROJECT, 2021
** serveur_message
** File description:
** serveur_message.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "serveur.h"

void add_msg(info_t **head, int code, const char *msg)
{
    info_t *element = malloc(sizeof(info_t));
    info_t *init = *head;

    element->msg = strdup(msg);
    element->code = code;
    element->next = NULL;
    if (init == NULL) {
        *head = element;
        return;
    }
    while (init->next != NULL)
        init = init->next;
    init->next = element;
}

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