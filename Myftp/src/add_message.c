/*
** EPITECH PROJECT, 2021
** add_message
** File description:
** add_message.c
*/

#include <stdlib.h>
#include <string.h>
#include "my_ftp.h"

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