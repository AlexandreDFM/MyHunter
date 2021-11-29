/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** Counts and returns the number of characters
*/

#include "my.h"

int my_strlen(char const *str)
{
    int counter;
    counter = 0;
    while (str[counter] != 0) {
        counter = counter + 1;
    }
    return (counter);
}
