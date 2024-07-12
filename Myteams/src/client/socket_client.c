/*
** EPITECH PROJECT, 2021
** socket_client
** File description:
** socket_client.c
*/

#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <strings.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include "client.h"

int create_socket_client(char *ip, int serveur)
{
    struct sockaddr_in sockaddr;
    socklen_t addrlen = sizeof(sockaddr);
    struct hostent *host;

    host = gethostbyname("localhost");
    char *hostname = inet_ntoa(*(struct in_addr *) host->h_addr);
    if (strcmp(ip, "localhost") == 0)
        ip = hostname;
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, NULL, 0);
    if (fd == -1)
        return (84);
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(serveur);
    sockaddr.sin_addr.s_addr = inet_addr(ip);
    if (connect(fd, (struct sockaddr *)&sockaddr, addrlen) == -1) {
        close(fd);
        return (84);
    }
    return (fd);
}