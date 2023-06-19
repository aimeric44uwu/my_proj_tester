/*
** EPITECH PROJECT, 2022
** palyndrome
** File description:
** arg_parser.c
*/

#include "my.h"

int check_for_trashs(my_func_args_t *args)
{
    for (int i = 1; i < args->ac; i++) {
        if (strcmp(args->av[i], "-h") != 0 && strncmp(args->av[i], "./", 2))
            return 84;
    }
    return 0;
}

static void av_parser(my_func_args_t *args, int i)
{
    if (strcmp(args->av[i], "-h") == 0) {
        args->flag_h = true;
        print_help();
    }
    if (strncmp(args->av[i], "./", 2) == 0) {
        args->path_one = true;
        args->path_one_str = args->av[i];
    }
}

static int verify_given_flags(my_func_args_t *args)
{
    int count = 0;
    if (args->path_one == true)
        count++;
    if (count > 1)
        return 84;
    return 0;
}

int parse_arg(int ac, char **av, my_func_args_t *args)
{
    init_everything_to_null(args);
    args->ac = ac;
    args->av = av;
    if (ac < 2)
        return error_wrong_args();
    for (int i = 1; i < ac; i++)
        av_parser(args, i);
    if (args->flag_h == true) {
        return 0;
    }
    if (check_for_trashs(args) != 0)
        return error_wrong_args();
    if (verify_given_flags(args) != 0)
        return error_wrong_args();
    return 0;
}
