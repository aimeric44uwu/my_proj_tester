/*
** EPITECH PROJECT, 2022
** test_criterion
** File description:
** test.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "../include/my.h"


void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

