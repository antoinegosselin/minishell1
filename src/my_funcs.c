/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_funcs
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"
#include "get_next_line.h"

int my_unsetenv(char ***env, char **args)
{
    int nb_args = count_args(args);

    if (nb_args == 1)
        my_putstr_error("unsetenv: Too few arguments.\n");
    else {
        for (int i = 1; args[i] != NULL; i++) {
            (*env) = unset_env((*env), args[i]);
        }
    }
    return (0);
}

int my_setenv(char ***env, char **args)
{
    int nb_args = count_args(args);

    if (nb_args == 1)
        print_env((*env));
    if (nb_args == 2)
        (*env) = set_env((*env), args[1], "");
    if (nb_args == 3)
        (*env) = set_env((*env), args[1], args[2]);
    if (nb_args > 3)
        my_putstr_error("setenv: Too many arguments.\n");
    return (0);
}

int my_cd(char ***env, char **args)
{
    int nb_args = count_args(args);

    check_env(env);
    if (nb_args == 1)
        (*env) = cd_home((*env));
    else if (nb_args == 2) {
        if (my_strcmp("-", args[1]) == 0)
            (*env) = cd_less((*env));
        else
            (*env) = cd_normal((*env), args[1]);
    }
    else
        my_putstr_error("cd: Too many arguments.\n");
    return (0);
}

int my_funcs(char ***env, char *buffer)
{
    int ret_val = 1;
    char **args = my_str_to_word_array(buffer, ' ');
    char *names[4] = {"cd", "env", "setenv", "unsetenv"};
    int (*tab[4])(char ***env, char **args) =
        {&my_cd, &my_env, &my_setenv, &my_unsetenv};

    for (int i = 0; i < 4; i++) {
        if (my_strcmp(names[i], args[0]) == 0)
            ret_val = tab[i](env, args);
    }
    free(args);
    return (ret_val);
}