/*
** EPITECH PROJECT, 2021
** dog
** File description:
** Function Dog of Hunter Game
*/

#include "./include/my.h"
#include "./include/myhunter.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void mouvementdog(sfVector2f *positiondog)
{
    positiondog->x += 20;
    if (positiondog->x >= 835 || positiondog->x < -68)
        positiondog->x = -68;
    if (positiondog->y == 642 || positiondog->y == -42)
        positiondog->y = -41;
}

void move_rectdog(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left == max_value) {
        rect->left = 0;
    } else {
        rect->left += 53;
    }
}

void clock_dog(sfClock *clock, sfIntRect *rect, sfVector2f *positiondog)
{
    if (sfClock_getElapsedTime(clock).microseconds > 150000.0) {
        move_rectdog(rect, 0, 265);
        mouvementdog(positiondog);
        sfClock_restart(clock);
    }
}

int start_adog(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfVector2f resize = {3, 3};
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();
    sfIntRect rectdog = {0, 0, 53, 45};
    sfVector2f positiondog = {0, 330};
    while (positiondog.x <= 120) {
        clock_dog(clock, &rectdog, &positiondog);
        display_b(window, hunter, sprite);
        sfSprite_setTexture(sprite->s_basicdog, sprite->t_basicdog, sfTrue);
        sfSprite_setTextureRect(sprite->s_basicdog, rectdog);
        sfSprite_setPosition(sprite->s_basicdog, positiondog);
        sfSprite_setScale(sprite->s_basicdog, resize);
        sfRenderWindow_drawSprite(window, sprite->s_basicdog, NULL);
        sfRenderWindow_display(window);
    }
}
