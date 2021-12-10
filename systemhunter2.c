/*
** EPITECH PROJECT, 2021
** systemhunter2
** File description:
** Function System of Hunter Game
*/

#include "./include/my.h"
#include "./include/myhunter.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <SFML/Audio.h>

void display_p(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfVector2f resize = {2.9, 2};
    sfSprite_setTexture(sprite->s_pause, sprite->t_pause, sfTrue);
    sfVector2f pauseposition = {328, 100};
    sfSprite_setPosition(sprite->s_pause, pauseposition);
    sfSprite_setScale(sprite->s_pause, resize);
    sfRenderWindow_drawSprite(window, sprite->s_pause, NULL);
}

void pause_game(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    display_p(window, hunter, sprite);
    play_bouton(window, hunter, sprite);
    quit_bouton(window, hunter, sprite);
    check_mouse(window, hunter, sprite);
    if (hunter->playvalid == 1 && sfMouse_isButtonPressed(sfMouseLeft) ||
    sfKeyboard_isKeyPressed(sfKeySpace)) {
        sfClock *clockwait = sfClock_create();
        while (sfClock_getElapsedTime(clockwait).microseconds < 200000.0);
        hunter->play = 1;
    }
    else if (hunter->quitvalid == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfRenderWindow_close(window);
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left == max_value) {
        rect->left = 0;
    } else {
        rect->left += 35;
    }
}

void clock_game(myhunter_t *hunter, sfIntRect *rect)
{
    if (sfClock_getElapsedTime(hunter->clock).microseconds > 100000.0) {
        move_rect(rect, 0, 70);
        mouvementduck(&hunter->positionduck, hunter);
        sfClock_restart(hunter->clock);
        if (hunter->play == 1 && sfMouse_isButtonPressed(sfMouseLeft) == 1) {
            hunter->nbhit -= 1;
        }
    }
}

int cursor(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprite)
{
    float posx = sfMouse_getPositionRenderWindow(window).x;
    float posy = sfMouse_getPositionRenderWindow(window).y;
    sfVector2f coord = {posx, posy};
    sfVector2f origin = {12, 12};
    sfSprite_setTexture(sprite->s_cursor, sprite->t_cursor, sfTrue);
    sfSprite_setOrigin(sprite->s_cursor, origin);
    sfSprite_setPosition(sprite->s_cursor, coord);
    sfRenderWindow_drawSprite(window, sprite->s_cursor, NULL);
    if (hunter->play == 1 && sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (sfMusic_getStatus(hunter->shot) == 0) {
            sfMusic_stop(hunter->shot);
            sfMusic_play(hunter->shot);
        }
    }
}
