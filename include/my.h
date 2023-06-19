/*
** EPITECH PROJECT, 2022
** my_proj_tester
** File description:
** my.h
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <fcntl.h>

typedef struct my_func_args_s {
    int ac;
    char **av;
    bool path_one;
    bool flag_h;
    char *path_one_str;
} my_func_args_t;

typedef struct my_projtest_s {
    my_func_args_t args;
} my_projtest_t;