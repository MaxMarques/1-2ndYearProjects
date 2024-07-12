/*
** EPITECH PROJECT, 2020
** test_create_response
** File description:
** test
*/

#include "test.h"
#include "serveur.h"
#include <stdio.h>
#include <criterion/logging.h>
#include <criterion/criterion.h>

Test(unit1, strcomb_test)
{
    char *res = my_strcomb("salut ", "les copains");

    cr_assert_arr_eq(res, "salut les copains", NULL);
}

Test(unit2, strcomb_test)
{
    char *res = my_strcomb("AAAAAAAAAA", "BBBBBBBBB");

    cr_assert_arr_eq(res, "AAAAAAAAAABBBBBBBBB", NULL);
}

Test(unit3, strcomb_test)
{
    char *res = my_strcomb(" ", " ");

    cr_assert_arr_eq(res, "  ", NULL);
}

Test(unit4, strcomb_test)
{
    char *res = my_strcomb("", "");

    cr_assert_arr_eq(res, "", NULL);
}

Test(unit5, opendata)
{
    char *test = "ntm markes";
    char *res = extract_name(&test);

    cr_assert_arr_eq(res, "ntm", NULL);
}

Test(unit6, opendata)
{
    char *test = "";
    char *res = extract_name(&test);

    cr_assert_arr_eq(res, "", NULL);
}

Test(unit7, opendata)
{
    char *test = NULL;
    char *res = extract_name(&test);

    cr_assert_arr_eq(res, NULL, NULL);
}

Test(unit8, opendata)
{
    char *test = NULL;
    char *res = extract_uuid(&test);

    cr_assert_arr_eq(res, NULL, NULL);
}

Test(unit9, opendata)
{
    char *test = "";
    char *res = extract_uuid(&test);

    cr_assert_arr_eq(res, "", NULL);
}

Test(unit10, opendata)
{
    char *test = "ntm markes";
    char *res = extract_uuid(&test);

    cr_assert_arr_eq(res, "ntm", NULL);
}

Test(unit11, opendata)
{
    char *test = "";
    char *res = extract_conv_path(&test);

    cr_assert_arr_eq(res, "", NULL);
}

Test(unit12, opendata)
{
    char *test = NULL;
    char *res = extract_conv_path(&test);

    cr_assert_arr_eq(res, NULL, NULL);
}

Test(unit13, opendata)
{
    char *test = "ntm markes";
    char *res = extract_conv_path(&test);

    cr_assert_arr_eq(res, "ntm", NULL);
}

Test(unit15, lib)
{
    FILE *fd = fopen("./libs/myteams/logging_client.h", "r");

    cr_assert_not_null(fd);
}

Test(unit16, lib)
{
    FILE *fd = fopen("./libs/myteams/logging_server.h", "r");

    cr_assert_not_null(fd);
}

Test(unit17, lib)
{
    FILE *fd = fopen("./libs/myteams/libmyteams.so", "r");

    cr_assert_not_null(fd);
}

Test(unit18, lib)
{
    FILE *fd = fopen("./include/serveur.h", "r");

    cr_assert_not_null(fd);
}

Test(unit19, lib)
{
    FILE *fd = fopen("./include/client.h", "r");

    cr_assert_not_null(fd);
}

Test(unit20, uuid_gen)
{
    char *tmp = uuid_generator();

    cr_assert_not_null(tmp);
}