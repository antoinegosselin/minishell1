/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** error
*/

#include <errno.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"

void error_execve(char *name)
{
    if (errno == ENOEXEC) {
        my_putstr_error(name);
        my_putstr_error(": Exec format error. Wrong Architecture.\n");
    } else {
        my_putstr_error(name);
        my_putstr_error(": ");
        my_putstr_error(strerror(errno));
        my_putstr_error(".\n");
    }
    exit (84);
}

void error_message(int ret_val)
{
    if (WTERMSIG(ret_val) == 8) {
        my_putstr_error("Floating exception\n");
    } else {
        my_putstr_error(strsignal(WTERMSIG(ret_val)));
        my_putstr_error("\n");
    }
}