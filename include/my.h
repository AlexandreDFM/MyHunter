/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** Library include
*/

#ifndef MY_H_
    #define MY_H_

int my_isneg(int nb);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_is_prime(int nb);
char *my_revstr(char *str);
void my_swap(int *a, int *b);
int my_find_prime_sup(int nb);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcapitalize(char *str);
int my_str_isnum(char const *str);
int my_compute_square_root(int nb);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isalpha(char const *str);
int my_str_isprintable(char const *str);
int my_rev_params(int argc, char **argv);
int my_showmem(char const *str, int size);
void my_sort_int_array(int *tab, int size);
int my_print_params(int argc, char **argv);
int my_compute_power_rec(int nb, int power);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strstr(char *str, char const *to_find);
char *my_strncpy(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncat(char *dest, char const *src, int nb);

#endif
