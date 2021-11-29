/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** Concatenates two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int counter = my_strlen(dest);
    while (src[i] != 0) {
        dest[counter + i] = src[i];
        i += 1;
    }
    dest[counter + i] = 0;
    return (dest);
}
