/*
** EPITECH PROJECT, 2022
** my_proj_tester
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av)
{
    my_projtest_t *projtest = malloc(sizeof(my_projtest_t));

    if (parse_arg(ac, av, &projtest->args) != 0)
        exit(84);
    return 0;
}
