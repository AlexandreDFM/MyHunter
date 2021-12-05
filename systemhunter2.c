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

void display_p(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    sfVector2f resize = {2.9, 2};
    sfSprite_setTexture(sprites->s_pause, sprites->t_pause, sfTrue);
    sfVector2f pauseposition = {328, 100};
    sfSprite_setPosition(sprites->s_pause, pauseposition);
    sfSprite_setScale(sprites->s_pause, resize);
    sfRenderWindow_drawSprite(window, sprites->s_pause, NULL);
}

void pause_game(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites, sfEvent event)
{
    display_p(window, hunter, sprites);
    play_bouton(window, hunter, sprites);
    quit_bouton(window, hunter, sprites);
    check_mouse(window, hunter, sprites);
    if (hunter->playvalid == 1 && event.type == sfEvtMouseButtonPressed ||
     sfKeyboard_isKeyPressed(sfKeySpace)) {
        sfClock *clockwait = sfClock_create();
        while (sfClock_getElapsedTime(clockwait).microseconds < 200000.0);
        hunter->play = 1;
    } else if (hunter->quitvalid == 1 && event.type == sfEvtMouseButtonPressed) {
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

void clock_game(myhunter_t *hunter, sfIntRect *rect, int offset, int max_value)
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

int cursor(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites, sfEvent event)
{
    float posx = sfMouse_getPositionRenderWindow(window).x;
    float posy = sfMouse_getPositionRenderWindow(window).y;
    sfVector2f coord = {posx, posy};
    sfVector2f origin = {12, 12};
    sfSprite_setTexture(sprites->s_cursor, sprites->t_cursor, sfTrue);
    sfSprite_setOrigin(sprites->s_cursor, origin);
    sfSprite_setPosition(sprites->s_cursor, coord);
    sfRenderWindow_drawSprite(window, sprites->s_cursor, NULL);
    if (hunter->play == 1 && sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (sfMusic_getStatus(hunter->shot) == 0) {
            sfMusic_stop(hunter->shot);
            sfMusic_play(hunter->shot);
        }
    }
}