/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include "my_ftp.h"

static void usage(void)
{
    FILE *fd = fopen("./usage.txt", "r");
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
            if (opendir(av[2]) == 0)
                return (84);
            else {
                int fd = create_socket(atoi(av[1]), 0);
                if (fd == -1)
                    return (84);
                if (managed_socket(fd, av[2]))
                    return (84);
            }
        } else
            return (84);
    } else
        return (84);
    return (0);
}