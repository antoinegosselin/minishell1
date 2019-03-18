/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** free
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void free_double(char **args)
{
    for (int i = 0; args[i] != NULL; i++) {
        free(args[i]);
    }
    free(args);
}

int free_and_ret(char **args, int ret_val, char *name, char **path)
{
    free_double(args);
    free_double(path);
    free(name);
    return (ret_val);
}