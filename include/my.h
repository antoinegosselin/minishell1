/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** prototypes
*/

#ifndef MY_H
#define MY_H

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char *str);
int my_isneg(int n);
char *my_strndup(char *str, int n);
int my_is_prime(int nb);
void my_putchar(char c);
void my_putstr_error(char const *str);
int my_put_nbr(int nb);
void my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char *str, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str, char c);
struct info_param *my_params_to_array(int ac, char **av);
char *my_strdup(char const *src);

#endif
