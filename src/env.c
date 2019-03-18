/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** env
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"

int count_args(char **env)
{
    int i = 0;

    while (env[i] != NULL)
        i++;
    return (i);
}

char **load_env(char **env)
{
    int i = count_args(env);
    int j;
    char **my_env;

    my_env = malloc(sizeof(char *) * (i + 1));
    for (j = 0; env[j] != NULL; j++) {
        my_env[j] = my_strndup(env[j], -1);
    }
    my_env[j] = NULL;
    return (my_env);
}

void print_env(char **env)
{
    my_show_word_array(env);
}

int my_env(char ***env, char **args)
{
    int nb_args = count_args(args);

    if (nb_args != 1) {
        my_putstr("env: '");
        my_putstr(args[1]);
        my_putstr("': No such file or directory\n");
    } else {
        print_env((*env));
    }
    return (0);
}