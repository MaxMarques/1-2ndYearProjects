/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

static void usage(void)
{
    FILE *fd = fopen("./src/client/usage.txt", "r");
    char *lineptr = NULL;
    size_t n = 0;

    while (getline(&lineptr, &n, fd) > 0)
        printf("%s", lineptr);
    fclose(fd);
}

int main(int ac, char *av[])
{
    if (av[1] != NULL) {
        if (strcmp(av[1], "-help") == 0) {
            usage();
            return (0);
        }
        else if (ac == 3) {
            int fd = create_socket_client(av[1], atoi(av[2]));
            if (fd == -1 || fd == 84)
                return (84);
            if (managed_socket_client(fd) == 84)
                return (84);
        } else
            return (84);
    } else
        return (84);
    return (0);
}