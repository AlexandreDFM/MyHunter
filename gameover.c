/*
** EPITECH PROJECT, 2021
** gameover.c
** File description:
** Display and restart game after Game Over
*/

#include "./include/my.h"
#include "./include/myhunter.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>

void display_go(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfVector2f resize = {2.9, 2};
    sfSprite_setTexture(sprite->s_go, sprite->t_go, sfTrue);
    sfVector2f goposition = {271, 200};
    sfSprite_setPosition(sprite->s_go, goposition);
    sfSprite_setScale(sprite->s_go, resize);
    sfRenderWindow_drawSprite(window, sprite->s_go, NULL);
}

void retry_or_close(sfRenderWindow *window, myhunter_t *hunter)
{
    if (sfKeyboard_isKeyPressed(sfKeyR) == 1) {
        hunter->play = 4;
        hunter->nbhit = 3;
    } else if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1) {
        hunter->nbhit = 3;
        sfRenderWindow_close(window);
    }
}

int check_shot(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfClock *goclock = sfClock_create();
    if (hunter->nbhit <= 0)
        sfRenderWindow_setMouseCursorGrabbed(window, sfFalse);
    while (hunter->nbhit <= 0) {
        while (sfClock_getElapsedTime(goclock).microseconds < 100000.0);
        hunter->play = -1;
        sfRenderWindow_clear(window, sfBlack);
        display_b(window, hunter, sprite);
        display_duck(window, hunter, sprite);
        display_b2(window, hunter, sprite);
        display_go(window, hunter, sprite);
        cursor(window, hunter, sprite);
        sfRenderWindow_display(window);
        retry_or_close(window, hunter);
    }
    sfClock_destroy(goclock);
}