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
#include <SFML/Audio.h>
#include <stdlib.h>

void check_cduck(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    sfFloatRect posduck = {sfSprite_getPosition(sprites->s_basicduck).x,
    sfSprite_getPosition(sprites->s_basicduck).y, 105, 117};
    float posmousex = sfMouse_getPositionRenderWindow(window).x;
    float posmousey = sfMouse_getPositionRenderWindow(window).y;
    hunter->duckonmouse = sfFloatRect_contains(&posduck, posmousex, posmousey);
}

void play_sound(myhunter_t *hunter)
{
    if (sfMusic_getStatus(hunter->shot) == 0) {
        sfMusic_stop(hunter->shot);
        sfMusic_play(hunter->shot);
    }
    if (sfMusic_getStatus(hunter->winshot) == 0) {
        sfMusic_stop(hunter->winshot);
        sfMusic_play(hunter->winshot);
    }
}

void changehit(myhunter_t *hunter)
{
    if (hunter->recthit2.width < 113)
        hunter->recthit2.width += 8;
    else
        hunter->recthit2.width = 41;
}

void mouvementduck(sfVector2f *positionduck, myhunter_t *hunter)
{
    if (hunter->nbtouchhit == 10) {
        hunter->nbtouchhit = 0;
        hunter->speeduck += 10;
    }
    positionduck->x += hunter->speeduck;
    if (positionduck->x >= 835 || positionduck->x < -68)
        positionduck->x = -68;
    if (positionduck->y == 642 || positionduck->y == -42)
        positionduck->y = -41;
}

int display_duck(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    sfVector2f resize = {3, 3};
    sfVector2f coord = sfSprite_getPosition(sprites->s_cursor);
    check_cduck(window, hunter, sprites);
    if (hunter->duckonmouse == 1 && 
    hunter->event.type == sfEvtMouseButtonPressed && hunter->play == 1) {
        hunter->scorenb += 100;
        hunter->nbtouchhit += 1;
        hunter->nbhit = 3;
        hunter->rectshot2.width = 26;
        changehit(hunter);
        play_sound(hunter);
        start_fduck(window, hunter, sprites);
        start_adog3(window, hunter, sprites);
        hunter->positionduck.x = -68;
        hunter->positionduck.y = rand() % 301;
    }
    sfSprite_setTexture(sprites->s_basicduck, sprites->t_basicduck, sfTrue);
    sfSprite_setTextureRect(sprites->s_basicduck, hunter->rectduck);
    sfSprite_setPosition(sprites->s_basicduck, hunter->positionduck);
    sfSprite_setScale(sprites->s_basicduck, resize);
    sfRenderWindow_drawSprite(window, sprites->s_basicduck, NULL);
}