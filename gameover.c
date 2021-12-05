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

void display_go(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    sfVector2f resize = {2.9, 2};
    sfSprite_setTexture(sprites->s_go, sprites->t_go, sfTrue);
    sfVector2f goposition = {271, 200};
    sfSprite_setPosition(sprites->s_go, goposition);
    sfSprite_setScale(sprites->s_go, resize);
    sfRenderWindow_drawSprite(window, sprites->s_go, NULL);
}

int check_shot(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    sfClock *goclock = sfClock_create();
    if (hunter->nbhit <= 0)
        sfRenderWindow_setMouseCursorGrabbed(window, sfFalse);
    while (hunter->nbhit <= 0) {
        while (sfClock_getElapsedTime(goclock).microseconds < 100000.0);
        hunter->play = -1;
        sfRenderWindow_clear(window, sfBlack);
        display_b(window, hunter, sprites);
        display_duck(window, hunter, sprites);
        display_b2(window, hunter, sprites);
        display_go(window, hunter, sprites);
        cursor(window, hunter, sprites);
        sfRenderWindow_display(window);
        if (sfKeyboard_isKeyPressed(sfKeyR) == 1) {
            hunter->play = 4;
            hunter->nbhit = 3;
        }
    }
    sfClock_destroy(goclock);
}