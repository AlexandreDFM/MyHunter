/*
** EPITECH PROJECT, 2021
** my_sort_int_array
** File description:
** Sorts an integer array order
*/

#include "my.h"

void my_sort_int_array(int *array, int size)
{
    int a = 0;
    for (int counter = 0; counter < size; ++counter){
        for (int counter2 = counter + 1; counter2 < size; ++counter2){
            if (array[counter] > array[counter2]){
                a = array[counter];
                array[counter] = array[counter2];
                array[counter2] = a;
            }
        }
    }
}
