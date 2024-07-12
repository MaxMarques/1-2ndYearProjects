/*
** EPITECH PROJECT, 2021
** login_cmd
** File description:
** login_cmd.c
*/

#include <stdlib.h>
#include <string.h>
#include "serveur.h"
#include <unistd.h>
#include <stdio.h>
#include <logging_server.h>

static void remove_char_string(char *str, char delete)
{
    char *src = NULL;
    char *dst = NULL;

    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != delete)
            dst++;
    }
    *dst = '\0';
}

void get_info_from_data(client_t *client, users_t **users, char *name)
{
    users_t *head = (*users);
    char *tmp = NULL;
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            client->uuid = head->uuid;
            client->conversation_path = head->conversation_path;
            head->connected = 1;
            return;
        }
        head = head->next;
    }
    client->uuid = uuid_generator();
    tmp = malloc(sizeof(char) * (strlen(name) + 26));
    strcat(strcat(strcpy(tmp, "./clients/"), name), "'s_conversations");
    client->conversation_path = tmp;
    FILE *fd = fopen("./database/users.csv", "a+");
    fprintf(fd, "\n%s,%s,%s,", client->uuid, name, client->conversation_path);
    add_user_status(users, client->conversation_path, name, client->uuid);
    server_event_user_created(client->uuid, client->name);
}

static void clean_login(client_t *client, users_t **users)
{
    if (strlen(client->argument[0]) > 32
    || strlen(client->argument[0]) < 1)
        add_msg(&client->info, 500,
        "This name must cont"
        "ain between 1 and 32 characteres");
    else if (client->argument[0][0] != '\"' ||
    client->argument[0][strlen(client->argument[0]) - 1] != '\"')
        add_msg(&client->info, 500, "Wrong syntax, enter -> \"NAME\"");
    else {
        remove_char_string(client->argument[0], '\"');
        client->name = client->argument[0];
        get_info_from_data(client, users, client->argument[0]);
        char *str = my_strcomb(client->uuid, " ");
        str = my_strcomb(str, client->name);
        add_msg(&client->info, 300, str);
        server_event_user_logged_in((char *const)client->uuid);
        client->flags |= LOGIN;
    }
}

void login_cmd(client_t *client, users_t **users)
{
    if (client->flags == LOGIN) {
        add_msg(&client->info, 300, "It's not possible to reconnect");
        if (&client->next != NULL)
            add_msg(&client->next->info, 300, "It's not possible to reconnect");
        return;
    }
    if (client->argument == NULL || client->argument[0] == NULL)
        return;
    if (client->argument[0][1] == 34)
        add_msg(&client->info, 500,
        "This name must contain between 1 and 32 characteres");
    clean_login(client, users);
}