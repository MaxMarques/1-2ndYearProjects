/*
** EPITECH PROJECT, 2021
** socket
** File description:
** socket.h
*/

#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include "my_ftp.h"

int create_socket(int serveur, int ip)
{
    struct sockaddr_in sockaddr;

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, NULL, 0);
    if (fd == -1)
        return (84);
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(serveur);
    sockaddr.sin_addr.s_addr = htonl(ip);
    if (bind(fd, (const struct sockaddr *) &sockaddr, sizeof(sockaddr)) == -1) {
        close(fd);
        perror(NULL);
        return (84);
    }
    return (fd);
}