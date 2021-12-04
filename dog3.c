/*
** EPITECH PROJECT, 2021
** dog2
** File description:
** Function Dog of Hunter Game
*/

#include "./include/my.h"
#include "./include/myhunter.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void mouvementdog3(sfVector2f *positiondog, myhunter_t *hunter)
{
    if (positiondog->y >= 300 && hunter->mouvementdogwin == 0) {
        positiondog->y += -20;
    } else if (positiondog->y <= 400) {
        positiondog->y += +20;
        hunter->mouvementdogwin = 1;
    }
}

void clock_dog3(sfClock *clock, sfIntRect *rect, sfVector2f *positiondog, myhunter_t *hunter)
{
    if (sfClock_getElapsedTime(clock).microseconds > 100000.0) {
        mouvementdog3(positiondog, hunter);
        sfClock_restart(clock);
    }
}

int start_animation_dog3(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites, sfVector2f positionduck)
{
    hunter->mouvementdogwin = 0;
    sfVector2f resize = {3, 3};
    sfTexture* texture_windog =
    sfTexture_createFromFile("./images/DogsCatch.png", NULL);
    sfSprite* sprite_windog = sfSprite_create();
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();
    sfIntRect rectdog = {0, 0, 49, 48};
    sfVector2f positiondog = {positionduck.x, 340};
    while ((int)positiondog.y <= 400) {
        clock_dog3(clock, &rectdog, &positiondog, hunter);
        displaybackground(window, hunter, sprites);
        sfSprite_setTexture(sprite_windog, texture_windog, sfTrue);
        sfSprite_setTextureRect(sprite_windog, rectdog);
        sfSprite_setPosition(sprite_windog, positiondog);
        sfSprite_setScale(sprite_windog, resize);
        sfRenderWindow_drawSprite(window, sprite_windog, NULL);
        displaybackground2(window, hunter, sprites);
        sfRenderWindow_display(window);
    }
}