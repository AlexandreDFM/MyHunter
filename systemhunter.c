/*
** EPITECH PROJECT, 2021
** systemhunter
** File description:
** Function System of Hunter Game
*/

#include "./include/my.h"
#include "./include/myhunter.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void start_game(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites, sfEvent event)
{
    sfSprite_setTexture(sprites->sprite_backgroundmenu, sprites->texture_backgroundmenu, sfTrue);
    sfRenderWindow_drawSprite(window, sprites->sprite_backgroundmenu, NULL);

    sfSprite_setTexture(sprites->sprite_title, sprites->texture_title, sfTrue);
    sfVector2f resizetitle = {0.30, 0.30};
    sfVector2f titleposition = {288, 50};
    sfSprite_setPosition(sprites->sprite_title, titleposition);
    sfSprite_setScale(sprites->sprite_title, resizetitle);
    sfRenderWindow_drawSprite(window, sprites->sprite_title, NULL);

    sfSprite_setTexture(sprites->sprite_boutonplay, sprites->texture_boutonplay, sfTrue);
    sfVector2f playboutonposition = {328, 200};
    sfSprite_setPosition(sprites->sprite_boutonplay, playboutonposition);
    sfRenderWindow_drawSprite(window, sprites->sprite_boutonplay, NULL);
    sfSprite_setTexture(sprites->sprite_boutonquit, sprites->texture_boutonquit, sfTrue);
    sfVector2f quitboutonposition = {328, 250};
    sfSprite_setPosition(sprites->sprite_boutonquit, quitboutonposition);
    sfRenderWindow_drawSprite(window, sprites->sprite_boutonquit, NULL);
    if (sfMouse_getPositionRenderWindow(window).x <= (int)sfSprite_getPosition(sprites->sprite_boutonplay).x + 144 && sfMouse_getPositionRenderWindow(window).x >= (int)sfSprite_getPosition(sprites->sprite_boutonplay).x && sfMouse_getPositionRenderWindow(window).y <= (int)sfSprite_getPosition(sprites->sprite_boutonplay).y + 50 && sfMouse_getPositionRenderWindow(window).y >= (int)sfSprite_getPosition(sprites->sprite_boutonplay).y && event.type == sfEvtMouseButtonPressed) {
        hunter->play = 1;
        start_animation_dog(window, hunter, sprites);
        start_animation_dog2(window, hunter, sprites);
    } else if (sfMouse_getPositionRenderWindow(window).x <= (int)sfSprite_getPosition(sprites->sprite_boutonquit).x + 144 && sfMouse_getPositionRenderWindow(window).x >= (int)sfSprite_getPosition(sprites->sprite_boutonquit).x && sfMouse_getPositionRenderWindow(window).y <= (int)sfSprite_getPosition(sprites->sprite_boutonquit).y + 50 && sfMouse_getPositionRenderWindow(window).y >= (int)sfSprite_getPosition(sprites->sprite_boutonquit).y && event.type == sfEvtMouseButtonPressed) {
        sfRenderWindow_close(window);
    }
}

void pause_game(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites, sfEvent event)
{
    sfVector2f playboutonposition = {328, 200};
    sfSprite_setPosition(sprites->sprite_boutonplay, playboutonposition);
    sfRenderWindow_drawSprite(window, sprites->sprite_boutonplay, NULL);
    sfSprite_setTexture(sprites->sprite_boutonquit, sprites->texture_boutonquit, sfTrue);
    sfVector2f quitboutonposition = {328, 250};
    sfSprite_setPosition(sprites->sprite_boutonquit, quitboutonposition);
    sfRenderWindow_drawSprite(window, sprites->sprite_boutonquit, NULL);
    if (sfMouse_getPositionRenderWindow(window).x <= (int)sfSprite_getPosition(sprites->sprite_boutonplay).x + 144 && sfMouse_getPositionRenderWindow(window).x >= (int)sfSprite_getPosition(sprites->sprite_boutonplay).x && sfMouse_getPositionRenderWindow(window).y <= (int)sfSprite_getPosition(sprites->sprite_boutonplay).y + 50 && sfMouse_getPositionRenderWindow(window).y >= (int)sfSprite_getPosition(sprites->sprite_boutonplay).y && event.type == sfEvtMouseButtonPressed) {
        hunter->play = 1;
    } else if (sfMouse_getPositionRenderWindow(window).x <= (int)sfSprite_getPosition(sprites->sprite_boutonquit).x + 144 && sfMouse_getPositionRenderWindow(window).x >= (int)sfSprite_getPosition(sprites->sprite_boutonquit).x && sfMouse_getPositionRenderWindow(window).y <= (int)sfSprite_getPosition(sprites->sprite_boutonquit).y + 50 && sfMouse_getPositionRenderWindow(window).y >= (int)sfSprite_getPosition(sprites->sprite_boutonquit).y && event.type == sfEvtMouseButtonPressed) {
        sfRenderWindow_close(window);
    }
}

void clock(myhunter_t *hunter, sfIntRect *rect, int offset, int max_value)
{
    if (sfClock_getElapsedTime(hunter->clock).microseconds > 100000.0) {
        move_rect(rect, 0, 70);
        mouvementduck(&hunter->positionduck);
        sfClock_restart(hunter->clock);
    }
}

int cursor(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites)
{
    sfVector2f coord = {(float)sfMouse_getPositionRenderWindow(window).x, (float)sfMouse_getPositionRenderWindow(window).y};
    sfVector2f origin = {12, 12};
    sfSprite_setTexture(sprites->sprite_cursor, sprites->texture_cursor, sfTrue);
    sfSprite_setOrigin(sprites->sprite_cursor, origin);
    sfSprite_setPosition(sprites->sprite_cursor, coord);
    sfRenderWindow_drawSprite(window, sprites->sprite_cursor, NULL);
}