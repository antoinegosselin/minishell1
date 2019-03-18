/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** verif
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"
#include "get_next_line.h"

void check_start(char ***env)
{
    char *env_name;
    int flags[4] = {0, 0, 0, 0};
    char *name[4] = {"PWD", "OLDPWD", "HOME", "PATH"};

    for (int i = 0; (*env)[i] != NULL; i++) {
        env_name = get_name((*env)[i]);
        for (int j = 0; j < 4; j++)
            flags[j] = (my_strcmp(env_name, name[j]) == 0) ? 1 : flags[j];
    }
    if (flags[0] == 0)
        (*env) =set_env((*env), "PWD", "/");
    if (flags[1] == 0)
        (*env) =set_env((*env), "OLDPWD", "/");
    if (flags[2] == 0)
        (*env) =set_env((*env), "HOME", "/");
    if (flags[3] == 0)
        (*env) =set_env((*env), "PATH",
            "/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin");
    free(env_name);
}

void check_env(char ***env)
{
    char *env_name;
    int flags[3] = {0, 0, 0};

    for (int i = 0; (*env)[i] != NULL; i++) {
        env_name = get_name((*env)[i]);
        if (my_strcmp(env_name, "PWD") == 0)
            flags[0] = 1;
        if (my_strcmp(env_name, "OLDPWD") == 0)
            flags[1] = 1;
        if (my_strcmp(env_name, "HOME") == 0)
            flags[2] = 1;
    }
    if (flags[0] == 0)
        (*env) =set_env((*env), "PWD", "/");
    if (flags[1] == 0)
        (*env) =set_env((*env), "OLDPWD", "/");
    if (flags[2] == 0)
        (*env) =set_env((*env), "HOME", "/");
    free(env_name);
}