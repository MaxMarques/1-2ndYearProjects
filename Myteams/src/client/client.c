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

static volatile bool sig = true;

static void update_var(int i)
{
    (void)i;
    sig = false;
}

static void signal_action(void)
{
    signal(SIGINT, update_var);
}

static int read_buffer(int socket, fd_set *rfds, client_t *client)
{
    char *line = malloc(sizeof(char) * SIZE_READ);

    if (FD_ISSET(socket, rfds)) {
        int read_files = read(socket, line, SIZE_READ);
        if (read_files <= 0)
            return (84);
        get_cmd(line, client);
    }
    return (0);
}

static int write_buffer(int socket, fd_set *rfds, client_t **client)
{
    char *msg = NULL;
    char *line = malloc(sizeof(64));
    size_t n = 0;

    if (FD_ISSET(STDIN_FILENO, rfds)) {
        if (getline(&line, &n, stdin) <= 0)
            return (84);
        size_t size_msg = strlen(line) + 7;
        msg = malloc(sizeof(char) * size_msg);
        snprintf(msg, size_msg, "%s", line);
        write(socket, msg, strlen(msg));
        (*client)->last_cmd = strtok(msg, " \n\r");
    }
    return (0);
}

int managed_socket_client(int socket)
{
    fd_set rfds;
    client_t *client = malloc(sizeof(client_t));
    client->last_cmd = NULL;
    signal_action();
    while (sig) {
        FD_ZERO(&rfds);
        FD_SET(STDIN_FILENO, &rfds);
        FD_SET(socket, &rfds);
        int slc = select(socket + 1, &rfds, NULL, NULL, NULL);
        if (slc == -1 && errno == EINTR) continue;
        if (slc == -1) break;
        if (read_buffer(socket, &rfds, client) == 84) {
            break;
        }
        if (write_buffer(socket, &rfds, &client) == 84) {
            break;
        }
    }
    close(socket);
    return (0);
}