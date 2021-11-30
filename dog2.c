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

void mouvementdog2(sfVector2f *positiondog)
{
    if (positiondog->x < 160) {
        positiondog->x += 20;
        positiondog->y += -80;
    } 
    if (positiondog->x >= 160) {
        positiondog->x += 20;
        positiondog->y += 80;
    }
}

void move_rectdog2(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left == max_value) {
        rect->left = 0;
    } else {
        rect->left += 46;
    }
}

void clock_dog2(sfClock *clock, sfIntRect *rect, sfVector2f *positiondog)
{
    if (sfClock_getElapsedTime(clock).microseconds > 180000.0) {
        move_rectdog2(rect, 0, 46);
        mouvementdog2(positiondog);
        sfClock_restart(clock);
    }
}

int start_animation_dog2(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    sfVector2f resize = {3, 3};
    sfTexture* texture_basicdog = sfTexture_createFromFile("./images/DuckHunt/DogsJump.png", NULL);
    sfSprite* sprite_basicdog = sfSprite_create();
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();
    sfIntRect rectdog = {0, 0, 46, 45};
    sfVector2f positiondog = {120, 330};
    while (positiondog.x <= 220) {
        clock_dog2(clock, &rectdog, &positiondog);
        displaybackground(window, hunter, sprites);
        sfSprite_setTexture(sprite_basicdog, texture_basicdog, sfTrue);
        sfSprite_setTextureRect(sprite_basicdog, rectdog);
        sfSprite_setPosition(sprite_basicdog, positiondog);
        sfSprite_setScale(sprite_basicdog, resize);
        sfRenderWindow_drawSprite(window, sprite_basicdog, NULL);
        if (positiondog.x >= 160)
            displaybackground2(window, hunter, sprites);
        sfRenderWindow_display(window);
    }
}