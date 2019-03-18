/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** setenv
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"

char *get_name(char *env)
{
    int i = 0;
    char *str;

    while (env[i] != '=')
        i++;
    str = my_strndup(env, i);
    return (str);
}

char **modif_env(char **env, int i, char *val, char *env_name)
{
    char *new_name = my_strncat(env_name, "=", -1);

    new_name = my_strncat(new_name, val, -1);
    env[i] = my_strndup(new_name, -1);
    free(new_name);
    return (env);
}

char **new_env(char **env, char *name, char *val)
{
    char *new_name = my_strncat(name, "=", -1);
    int i = count_args(env);
    int j;
    char **new_env;

    new_env = malloc(sizeof(char *) * (i + 1));
    new_name = my_strncat(new_name, val, -1);
    for (j = 0; env[j] != NULL; j++) {
        new_env[j] = my_strndup(env[j], -1);
    }
    new_env[j] = my_strndup(new_name, -1);
    new_env[j + 1] = NULL;
    return (new_env);
}

char **set_env(char **env, char *name, char *val)
{
    char *env_name;

    if (my_str_is_alphanum(name) == 0) {
        my_putstr_error("setenv: Variable name must");
        my_putstr_error(" contain alphanumeric characters.\n");
        return (env);
    }
    for (int i = 0; env[i] != NULL; i++) {
        env_name = get_name(env[i]);
        if (my_strcmp(env_name, name) == 0)
            return (modif_env(env, i, val, env_name));
    }
    free(env_name);
    return (new_env(env, name, val));
}