/*
** EPITECH PROJECT, 2021
** duck.c
** File description:
** Function relatives of duck
*/

#include "./include/my.h"
#include "./include/myhunter.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>

void reset_duck(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    hunter->scorenb += 100;
    hunter->nbtouchhit += 1;
    hunter->nbhit = 3;
    hunter->rectshot2.width = 26;
    changehit(hunter);
    play_sound(hunter);
    start_fduck(window, hunter, sprite);
    start_adog3(window, hunter, sprite);
    hunter->positionduck.x = -68;
    hunter->positionduck.y = rand() % 301;
}
