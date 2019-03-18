/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"
#include "get_next_line.h"

int check_args(char *buffer)
{
    int ret;
    char **args = my_str_to_word_array(buffer, ' ');

    if (args[0] == NULL)
        ret = 0;
    else
        ret = 1;
    free_double(args);
    return (ret);
}

int end(int fd, int ret_val)
{
    if (isatty(fd) == 1)
        my_putstr("exit\n");
    return (ret_val);
}

int loop(char **env, int fd)
{
    char *buffer;
    int ret_val = 0;

    while (1) {
        if (isatty(fd) == 1)
            my_putstr("$> ");
        buffer = get_next_line(0);
        if (buffer == NULL)
            return (end(fd, ret_val));
        if (check_args(buffer) == 0)
            continue;
        if (my_strcmp(buffer, "exit") == 0)
            return (end(fd, 0));
        if (my_funcs(&env, buffer) == 0)
            continue;
        if ((ret_val = simple_exec(buffer)) != -1)
            continue;
        ret_val = sys_func(env, buffer);
    }
}

int main(int ac, char **av, char **env)
{
    char **my_env;
    int fd = STDIN_FILENO;
    int ret_val;

    if (ac != 1)
        return (84);
    av[ac - 1] = "";
    my_env = load_env(env);
    check_start(&my_env);
    ret_val = loop(my_env, fd);
    free_double(my_env);
    return (ret_val);
}