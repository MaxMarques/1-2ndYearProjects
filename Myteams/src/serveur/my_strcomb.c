/*
** EPITECH PROJECT, 2021
** my_strcomb
** File description:
** my_strcomb.c
*/

#include <stdlib.h>
#include <string.h>
#include "serveur.h"

char *my_strcomb(char *str1, char *str2)
{
    char *str = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(str, str1);
    strcat(str, str2);

    return (str);
}