/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serveur.h"

static void usage(void)
{
    FILE *fd = fopen("./src/serveur/usage.txt", "r");
    char *lineptr = NULL;
    size_t n = 0;

    while (getline(&lineptr, &n, fd) > 0)
        printf("%s", lineptr);
    fclose(fd);
}

static int error_serv(char *av)
{
    for (size_t i = 0; i < strlen(av); i++) {
        if (av[i] < '0' || av[i] > '9')
            return (84);
    }
    return (0);
}

int main(int ac, char *av[])
{
    if (av[1] != NULL) {
        if (strcmp(av[1], "-help") == 0) {
            usage();
            return (0);
        }
        else if (ac == 2) {
            if (error_serv(av[1]) == 84)
                return (84);
            int fd = create_socket_serveur(atoi(av[1]), 0);
            if (fd == -1 || fd == 84)
                return (84);
            if (managed_socket_serveur(fd) == 84)
                return (84);
        } else {
            usage();
            return (84);
        }
    } else
        return (84);
    return (0);
}