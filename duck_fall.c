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
#include <stdlib.h>

void mouvementduckfall(sfVector2f *positiondog)
{
    positiondog->y += 100;
}

void move_rectduckfall(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left == max_value) {
        rect->left = 0;
    } else {
        rect->left += 32;
    }
}

void clock_duck_fall(sfClock *clock, sfIntRect *rectduckfall, sfVector2f *positionduckfall)
{
    if (sfClock_getElapsedTime(clock).microseconds > 120000.0) {
        move_rectduckfall(rectduckfall, 0, 120);
        mouvementduckfall(positionduckfall);
        sfClock_restart(clock);
    }
}

int display_duck_fall(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites, sfVector2f positionduck)
{
    sfVector2f resize = {3, 3};
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();
    sfVector2f positionduckfall = {(int)positionduck.x, (int)positionduck.y};
    sfIntRect rectduckfall = {0, 0, 35, 32};
    while ((int)positionduckfall.y <= 500) {
        clock_duck_fall(clock, &rectduckfall, &positionduckfall);
        displaybackground(window, hunter, sprites);
        sfSprite_setTexture(sprites->sprite_fallduck, sprites->texture_fallduck, sfTrue);
        sfSprite_setTextureRect(sprites->sprite_fallduck, rectduckfall);
        sfSprite_setPosition(sprites->sprite_fallduck, positionduckfall);
        sfSprite_setScale(sprites->sprite_fallduck, resize);
        sfRenderWindow_drawSprite(window, sprites->sprite_fallduck, NULL);
        displaybackground2(window, hunter, sprites);
        sfRenderWindow_display(window);
    }
}