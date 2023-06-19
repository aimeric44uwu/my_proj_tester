/*
** EPITECH PROJECT, 2022
** my_fast_a_tool
** File description:
** init.c
*/

#include "my.h"

void init_everything_to_null(my_func_args_t *args)
{
    args->ac = 0;
    args->av = NULL;
    args->flag_h = false;
    args->path_one = false;
    args->path_one_str = NULL;
}
