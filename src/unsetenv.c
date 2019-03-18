/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** unsetenv
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"

int find_index(char **env, char *name)
{
    int good_index = -1;
    char *env_name;

    for (int i = 0; env[i] != NULL; i++) {
        env_name = get_name(env[i]);
        if (my_strcmp(env_name, name) == 0)
            good_index = i;
    }
    free(env_name);
    return (good_index);
}

char **remove_env(char **env, int index)
{
    int i = 0;
    int j = 0;
    char **new_env;
    int nb_args = count_args(env);

    new_env = malloc(sizeof(char *) * (nb_args));
    for (; env[i] != NULL; i++) {
        if (i == index) {
            continue;
        } else {
            new_env[j] = my_strndup(env[i], -1);
            j++;
        }
    }
    new_env[j] = NULL;
    return (new_env);
}

char **unset_env(char **env, char *name)
{
    int index = find_index(env, name);

    if (index == -1)
        return (env);
    else {
        env = remove_env(env, index);
    }
    return (env);
}