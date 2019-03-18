/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell
*/

#ifndef MINISHELL_H
#define MINISHELL_H

char **set_env(char **env, char *name, char *val);
char **new_env(char **env, char *name, char *val);
char **modif_env(char **env, int i, char *val, char *env_name);
char *get_name(char *env);
void print_env(char **env);
int count_args(char **env);
char **load_env(char **env);
int loop(char **env, int fd);
char **remove_env(char **env, int index);
char **unset_env(char **env, char *name);
int find_index(char **env, char *name);
int my_funcs(char ***env, char *buffer);
int my_env(char ***env, char **args);
int my_cd(char ***env, char **args);
int my_setenv(char ***env, char **args);
int my_unsetenv(char ***env, char **args);
char **cd_home(char **env);
char **cd_normal(char **env, char *path);
void check_env(char ***env);
void check_start(char ***env);
char **cd_less(char **env);
int my_str_is_alphanum(char *str);
int my_exec(char **args);
int simple_exec(char *buffer);
int sys_func(char **env, char *buffer);
void free_double(char **args);
void error_message(int ret_val);
void error_execve(char *name);
int free_and_ret(char **args, int ret_val, char *name, char **path);

#endif //MINISHELL_H
