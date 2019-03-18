/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** cd
*/

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"
#include "get_next_line.h"

void cd_err(char *path)
{
    my_putstr_error(path);
    my_putstr_error(": ");
    perror("");
}

char **new_env_cd(char **env, char *pwd)
{
    char *env_name;
    char *buff = NULL;
    size_t size = 0;

    for (int j = 0; env[j] != NULL; j++) {
        env_name = get_name(env[j]);
        if (my_strcmp(env_name, "PWD") == 0) {
            buff = getcwd(buff, size);
            env[j] = my_strndup(my_strncat("PWD=", buff, -1), -1);
        }
        if (my_strcmp(env_name, "OLDPWD") == 0)
            env[j] = my_strndup(my_strncat("OLDPWD=", pwd, -1), -1);
    }
    return (env);
}

char **cd_normal(char **env, char *path)
{
    char *env_name;
    char *pwd;
    int ret_val;

    for (int i = 0; env[i] != NULL; i++) {
        env_name = get_name(env[i]);
        if (my_strcmp(env_name, "PWD") == 0)
            pwd = my_strndup(env[i] + 4, -1);
    }
    ret_val = chdir(path);
    if (ret_val == -1) {
        cd_err(path);
        return (env);
    }
    return (new_env_cd(env, pwd));
}

char **cd_home(char **env)
{
    char *pwd;
    char *home;
    char *env_name;
    int ret_val;

    for (int i = 0; env[i] != NULL; i++) {
        env_name = get_name(env[i]);
        if (my_strcmp(env_name, "PWD") == 0)
            pwd = my_strndup(env[i] + 4, -1);
        if (my_strcmp(env_name, "HOME") == 0)
            home = my_strndup(env[i] + 5, -1);
    }
    ret_val = chdir(home);
    if (ret_val == -1) {
        my_putstr_error("cd: Can't change to home directory.\n");
        return (env);
    }
    return (new_env_cd(env, pwd));
}

char **cd_less(char **env)
{
    char *pwd;
    char *path;
    char *env_name;
    int ret_val;

    for (int i = 0; env[i] != NULL; i++) {
        env_name = get_name(env[i]);
        if (my_strcmp(env_name, "PWD") == 0)
            pwd = my_strndup(env[i] + 4, -1);
        if (my_strcmp(env_name, "OLDPWD") == 0)
            path = my_strndup(env[i] + 7, -1);
    }
    ret_val = chdir(path);
    if (ret_val == -1) {
        cd_err(path);
        return (env);
    }
    return (new_env_cd(env, pwd));
}