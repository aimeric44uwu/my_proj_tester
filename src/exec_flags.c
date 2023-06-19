/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** exec_flags.c
*/

#include "my.h"

int exec_flags(my_projtest_t *projtstruct)
{
    if (projtstruct->args.path_one == true)
        return flag_one(projtstruct);
    return 84;
}
