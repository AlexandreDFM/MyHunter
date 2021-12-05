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

void mouvementdog3(myhunter_t *hunter)
{
    if (hunter->positiondogwin.y >= 300 && hunter->mouvementdogwin == 0) {
        hunter->positiondogwin.y += -20;
    } else if (hunter->positiondogwin.y <= 400) {
        hunter->positiondogwin.y += +20;
        hunter->mouvementdogwin = 1;
    }
}

void clock_dog3(sfClock *clock, sfIntRect *rect, myhunter_t *hunter)
{
    if (sfClock_getElapsedTime(clock).microseconds > 100000.0) {
        mouvementdog3(hunter);
        sfClock_restart(clock);
    }
}

int start_adog3(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    hunter->mouvementdogwin = 0;
    sfVector2f resize = {3, 3};
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();
    sfIntRect rectdog = {0, 0, 49, 48};
    sfVector2f positiondogwin = {hunter->positionduck.x, 340};
    hunter->positiondogwin = positiondogwin;
    while ((int)hunter->positiondogwin.y <= 400) {
        clock_dog3(clock, &rectdog, hunter);
        display_b(window, hunter, sprites);
        sfSprite_setTexture(sprites->s_windog, sprites->t_windog, sfTrue);
        sfSprite_setTextureRect(sprites->s_windog, rectdog);
        sfSprite_setPosition(sprites->s_windog, hunter->positiondogwin);
        sfSprite_setScale(sprites->s_windog, resize);
        sfRenderWindow_drawSprite(window, sprites->s_windog, NULL);
        display_b2(window, hunter, sprites);
        sfRenderWindow_display(window);
    }
}