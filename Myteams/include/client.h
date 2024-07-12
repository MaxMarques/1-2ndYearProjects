/*
** EPITECH PROJECT, 2021
** client
** File description:
** client.h
*/

#ifndef _CLIENT_
#define _CLIENT_

#define SIZE_READ 256

typedef struct client {

    char *last_cmd;

} client_t;

int create_socket_client(char *ip, int port);
int managed_socket_client(int socket);
char *buffer_management(void);
void login_client(char *cmd, char *line);
void logout_client(char *cmd, char *line);
void users_client(char *cmd, char *line);
void get_cmd(char *buffer, client_t *client);

#endif