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

void mouvementduckfall(myhunter_t *hunter)
{
    hunter->positionduckfall.y += 100;
}

void move_rectduckfall(myhunter_t *hunter, int offset, int max_value)
{
    if (hunter->rectduckfall.left == max_value) {
        hunter->rectduckfall.left = 0;
    } else {
        hunter->rectduckfall.left += 32;
    }
}

void clock_duck_fall(sfClock *clock, myhunter_t *hunter)
{
    if (sfClock_getElapsedTime(clock).microseconds > 120000.0) {
        move_rectduckfall(hunter, 0, 120);
        mouvementduckfall(hunter);
        sfClock_restart(clock);
    }
}

int start_fduck(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    sfVector2f resize = {3, 3};
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();
    int posx = hunter->positionduck.x, posy = hunter->positionduck.y;
    sfVector2f positionduckfall = {posx, posy};
    hunter->positionduckfall = positionduckfall;
    while (hunter->positionduckfall.y <= 500) {
        clock_duck_fall(clock, hunter);
        display_b(window, hunter, sprites);
        sfSprite_setTexture(sprites->s_fallduck, sprites->t_fallduck, sfTrue);
        sfSprite_setTextureRect(sprites->s_fallduck, hunter->rectduckfall);
        sfSprite_setPosition(sprites->s_fallduck, hunter->positionduckfall);
        sfSprite_setScale(sprites->s_fallduck, resize);
        sfRenderWindow_drawSprite(window, sprites->s_fallduck, NULL);
        display_b2(window, hunter, sprites);
        sfRenderWindow_display(window);
    }
    hunter->rectduckfall.left = 0;
}