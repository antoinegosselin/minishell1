/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** exec
*/

#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"

int my_exec(char **args)
{
    int ret_val = 0;
    int cpid;

    cpid = fork();
    if (cpid == -1)
        exit (84);
    if (cpid == 0) {
        execve(args[0], args, NULL);
        error_execve(args[0]);
    } else {
        wait(&ret_val);
        if (WIFEXITED(ret_val))
            return (WEXITSTATUS(ret_val));
        if (WIFSIGNALED(ret_val))
            error_message(ret_val);
    }
    return (WTERMSIG(ret_val) + 128);
}

int simple_exec(char *buffer)
{
    char **args = my_str_to_word_array(buffer, ' ');
    int ret_val;

    if (args[0][0] != '.' && args[0][1] != '/') {
        if (access(args[0], F_OK) == -1)
            return (-1);
        if (access(args[0], X_OK) == -1)
            return (-1);
    }
    ret_val = my_exec(args);
    free_double(args);
    return (ret_val);
}

char *get_path(char **env)
{
    char *path;
    char *env_name;

    for (int i = 0; env[i] != NULL; i++) {
        env_name = get_name(env[i]);
        if (my_strcmp(env_name, "PATH") == 0)
            path = my_strndup(env[i] + 5, -1);
    }
    free(env_name);
    return (path);
}

int sys_func(char **env, char *buffer)
{
    char **args = my_str_to_word_array(buffer, ' ');
    char *path = get_path(env);
    char **path_args = my_str_to_word_array(path, ':');
    char *name;
    int ret_val;

    for (int i = 0; path_args[i] != NULL; i++) {
        name = my_strncat(my_strndup(path_args[i], -1), "/", -1);
        name = my_strncat(name, my_strndup(args[0], -1), -1);
        if (access(name, F_OK) == -1)
            continue;
        if (access(name, X_OK) == -1)
            continue;
        args[0] = my_strndup(name, -1);
        ret_val = my_exec(args);
        return (free_and_ret(args, ret_val, name, path_args));
    }
    my_putstr_error(args[0]);
    my_putstr_error(": Command not found.\n");
    return (free_and_ret(args, 1, name, path_args));
}