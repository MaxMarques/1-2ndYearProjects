/*
** EPITECH PROJECT, 2021
** my_ftp
** File description:
** my_ftp.h
*/

#ifndef _FTP_
#define _FTP_

#include <linux/limits.h>
#include <stdbool.h>
#define SIZE_READ 256

typedef struct info {
    int code;
    char *msg;
    struct info *next;
} info_t;

typedef struct client {
    bool quit;
    bool login;
    bool pswd;
    bool user;
    bool valide;
    int fd;
    struct client *next;
    char *order;
    char *argument;
    char cwd[PATH_MAX];
    info_t *info;
} client_t;

void list_delete_element(client_t **client, client_t *delete);
int create_socket(int serveur, int ip);
int managed_socket(int socket, char *av);
void read_cmd(client_t *client);
void print_info(int fd, info_t **info);
void add_msg(info_t **head, int code, const char *msg);
void new_client(client_t **head, int socket, char *av);
void free_client(client_t *client);
void parser_commande(client_t *client, char *buffer);
void free_info(info_t *info);
void user_cmd(client_t *client);
void cdup_cmd(client_t *client);
void cwd_cmd(client_t *client);
void dele_cmd(client_t *client);
void help_cmd(client_t *client);
void list_cmd(client_t *client);
void noop_cmd(client_t *client);
void pass_cmd(client_t *client);
void pasv_cmd(client_t *client);
void port_cmd(client_t *client);
void pwd_cmd(client_t *client);
void quit_cmd(client_t *client);
void retr_cmd(client_t *client);
void stor_cmd(client_t *client);

#endif