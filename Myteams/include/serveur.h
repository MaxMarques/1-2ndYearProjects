/*
** EPITECH PROJECT, 2021
** serveur
** File description:
** serveur.h
*/

#ifndef _SERVEUR_
#define _SERVEUR_

#include <stdbool.h>
#include <sys/select.h>
#define SIZE_READ 256

enum CMD {
    QUIT = 1,
    LOGIN = 1 << 1,
};

typedef struct info {
    int code;
    char *msg;
    struct info *next;
} info_t;

typedef struct client {
    int fd;
    struct client *next;
    info_t *info;
    char *order;
    char **argument;
    int flags;
    char *uuid;
    char *name;
    char *conversation_path;
    char *team_use;
    char *channel_use;
    char *thread_use;
} client_t;

typedef struct sub {

    struct sub *next;
    char *team_uuid;

} sub_t;

typedef struct users {

    struct users *next;
    struct sub *sub;
    char *uuid;
    char *name;
    char *conversation_path;
    int connected;
} users_t;

typedef struct reply {
    struct team *next;
    char *reply;
} reply_t;

typedef struct thread {
    struct team *next;
    char *uuid;
    char *name;
    char *message;
    reply_t *reply;
} thread_t;

typedef struct channel {
    struct team *next;
    char *uuid;
    char *name;
    char *description;
    thread_t *thread;
} channel_t;

typedef struct team {
    struct team *next;
    char *uuid;
    char *name;
    char *description;
    channel_t *channel;
} team_t;

int create_socket_serveur(int serveur, int ip);
int managed_socket_serveur(int socket);
void new_client(client_t **head, int socket);
void parser_commande(client_t *client, users_t **users, char *buffer);
void free_client(client_t *client);
void free_info(info_t *info);
void add_msg(info_t **head, int code, const char *msg);
void print_info(int fd, info_t **info);
void list_delete_element(client_t **client, client_t *delete);
void quit_cmd(client_t *client, users_t **users);
void logout_cmd(client_t *client, users_t **users);
void login_cmd(client_t *client, users_t **users);
void help_cmd(client_t *client, users_t **users);
void users_cmd(client_t *client, users_t **users);
void create_cmd(client_t *client, users_t **users);
void use_cmd(client_t *client, users_t **users);
void socket_client_read(fd_set *rfds, int socket, client_t *client, int *max);
void socket_client_write(fd_set *write, client_t *client);
void read_buffer(client_t **client, users_t **users, fd_set *rfds);
void write_buffer(client_t **client, fd_set *write);
void close_client_socket(client_t **client);
char *my_strcomb(char *str1, char *str2);
int get_existing_clients(client_t **head);
char *uuid_generator(void);
char *extract_uuid(char **buffer);
char *extract_name(char **buffer);
char *extract_conv_path(char **buffer);

int check_data_dir(void);
int create_data_dir(void);
int create_csv_users(void);
int get_users(users_t **head);
int check_data_file(void);
int get_existing_users(users_t **head);

int is_user_exist(const char *name, client_t **head);
void add_user(users_t **head, char *conversation_path, char *name, char *uuid);
void add_user_status(users_t **head, char *conversation_path,
char *name, char *uuid);

#endif