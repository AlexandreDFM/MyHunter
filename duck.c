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

void mouvementduck(sfVector2f *positionduck)
{
    //base -> 5
    positionduck->x += 25;
    if (positionduck->x >= 835 || positionduck->x < -68)
        positionduck->x = -68;
    if (positionduck->y == 642 || positionduck->y == -42)
        positionduck->y = -41;
}

int displayduck(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites, sfEvent event)
{
    sfVector2f resize = {3, 3};
    sfVector2f coord = sfSprite_getPosition(sprites->sprite_cursor);
    sfVector2f positionduck = sfSprite_getPosition(sprites->sprite_basicduck);
    if ((int)sfSprite_getPosition(sprites->sprite_basicduck).x <= sfMouse_getPositionRenderWindow(window).x + 105 && (int)sfSprite_getPosition(sprites->sprite_basicduck).x >= sfMouse_getPositionRenderWindow(window).x - 105 && (int)sfSprite_getPosition(sprites->sprite_basicduck).y <= sfMouse_getPositionRenderWindow(window).y + 123 && (int)sfSprite_getPosition(sprites->sprite_basicduck).y >= sfMouse_getPositionRenderWindow(window).y - 123 && event.type == sfEvtMouseButtonPressed && hunter->play == 1) {
        hunter->positionduck.x = -68;
        hunter->positionduck.y = rand() % 301;
        hunter->scorenb += 100;
        if (sfMusic_getStatus(hunter->shoot) == 0) {
            sfMusic_stop(hunter->shoot);
            sfMusic_play(hunter->shoot);
        }
        if (sfMusic_getStatus(hunter->winshoot) == 0) {
            sfMusic_stop(hunter->winshoot);
            sfMusic_play(hunter->winshoot);
        }
        display_duck_fall(window, hunter, sprites, positionduck);
        start_animation_dog3(window, hunter, sprites, positionduck);
    }
    sfSprite_setTexture(sprites->sprite_basicduck, sprites->texture_basicduck, sfTrue);
    sfSprite_setTextureRect(sprites->sprite_basicduck, hunter->rectduck);
    sfSprite_setPosition(sprites->sprite_basicduck, hunter->positionduck);
    sfSprite_setScale(sprites->sprite_basicduck, resize);
    sfRenderWindow_drawSprite(window, sprites->sprite_basicduck, NULL);
}