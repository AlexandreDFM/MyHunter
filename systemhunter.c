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
#include <SFML/Audio.h>

void boutonplay(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    sfSprite_setTexture(sprites->sprite_boutonplay, sprites->texture_boutonplay, sfTrue);
    sfVector2f playboutonposition = {328, 200};
    sfSprite_setPosition(sprites->sprite_boutonplay, playboutonposition);
    sfRenderWindow_drawSprite(window, sprites->sprite_boutonplay, NULL);
}

void boutonquit(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    sfSprite_setTexture(sprites->sprite_boutonquit, sprites->texture_boutonquit, sfTrue);
    sfVector2f quitboutonposition = {328, 250};
    sfSprite_setPosition(sprites->sprite_boutonquit, quitboutonposition);
    sfRenderWindow_drawSprite(window, sprites->sprite_boutonquit, NULL);
}

void start_game(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites, sfEvent event)
{
    if (sfMusic_getStatus(hunter->music) == 0) {
        sfMusic_play(hunter->music);
        hunter->musicplayed = 1;
    }
    sfSprite_setTexture(sprites->sprite_backgroundmenu, sprites->texture_backgroundmenu, sfTrue);
    sfRenderWindow_drawSprite(window, sprites->sprite_backgroundmenu, NULL);

    sfSprite_setTexture(sprites->sprite_title, sprites->texture_title, sfTrue);
    sfVector2f resizetitle = {0.30, 0.30};
    sfVector2f titleposition = {288, 50};
    sfSprite_setPosition(sprites->sprite_title, titleposition);
    sfSprite_setScale(sprites->sprite_title, resizetitle);
    sfRenderWindow_drawSprite(window, sprites->sprite_title, NULL);

    boutonplay(window, hunter, sprites);
    //sfSprite_setTexture(sprites->sprite_boutonplay, sprites->texture_boutonplay, sfTrue);
    //sfVector2f playboutonposition = {328, 200};
    //sfSprite_setPosition(sprites->sprite_boutonplay, playboutonposition);
    //sfRenderWindow_drawSprite(window, sprites->sprite_boutonplay, NULL);

    boutonquit(window, hunter, sprites);
    //sfSprite_setTexture(sprites->sprite_boutonquit, sprites->texture_boutonquit, sfTrue);
    //sfVector2f quitboutonposition = {328, 250};
    //sfSprite_setPosition(sprites->sprite_boutonquit, quitboutonposition);
    //sfRenderWindow_drawSprite(window, sprites->sprite_boutonquit, NULL);

    sfFloatRect posplay = {sfSprite_getPosition(sprites->sprite_boutonplay).x,
    sfSprite_getPosition(sprites->sprite_boutonplay).y, 144, 50};
    sfFloatRect quitplay = {sfSprite_getPosition(sprites->sprite_boutonquit).x,
    sfSprite_getPosition(sprites->sprite_boutonquit).y, 144, 50};
    //sfIntRect_contains();
    int playvalid = sfFloatRect_contains(&posplay, sfMouse_getPositionRenderWindow(window).x, sfMouse_getPositionRenderWindow(window).y);
    int quitvalid = sfFloatRect_contains(&quitplay,sfMouse_getPositionRenderWindow(window).x, sfMouse_getPositionRenderWindow(window).y);
    if (playvalid == 1 && event.type == sfEvtMouseButtonPressed) {
        hunter->play = 1;
        hunter->musicplayed = 0;
        sfMusic_destroy(hunter->music);
        start_animation_dog(window, hunter, sprites);
        start_animation_dog2(window, hunter, sprites);
    } else if (quitvalid == 1 && event.type == sfEvtMouseButtonPressed) {
        sfMusic_destroy(hunter->music);
        sfRenderWindow_close(window);
    }
}

void pause_game(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites, sfEvent event)
{
    boutonplay(window, hunter, sprites);
    boutonquit(window, hunter, sprites);
    if (sfMouse_getPositionRenderWindow(window).x <= (int)sfSprite_getPosition(sprites->sprite_boutonplay).x + 144 && sfMouse_getPositionRenderWindow(window).x >= (int)sfSprite_getPosition(sprites->sprite_boutonplay).x && sfMouse_getPositionRenderWindow(window).y <= (int)sfSprite_getPosition(sprites->sprite_boutonplay).y + 50 && sfMouse_getPositionRenderWindow(window).y >= (int)sfSprite_getPosition(sprites->sprite_boutonplay).y && event.type == sfEvtMouseButtonPressed) {
        hunter->play = 1;
    } else if (sfMouse_getPositionRenderWindow(window).x <= (int)sfSprite_getPosition(sprites->sprite_boutonquit).x + 144 && sfMouse_getPositionRenderWindow(window).x >= (int)sfSprite_getPosition(sprites->sprite_boutonquit).x && sfMouse_getPositionRenderWindow(window).y <= (int)sfSprite_getPosition(sprites->sprite_boutonquit).y + 50 && sfMouse_getPositionRenderWindow(window).y >= (int)sfSprite_getPosition(sprites->sprite_boutonquit).y && event.type == sfEvtMouseButtonPressed) {
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
        mouvementduck(&hunter->positionduck);
        sfClock_restart(hunter->clock);
    }
}

int cursor(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites, sfEvent event)
{
    sfVector2f coord = {(float)sfMouse_getPositionRenderWindow(window).x, (float)sfMouse_getPositionRenderWindow(window).y};
    sfVector2f origin = {12, 12};
    sfSprite_setTexture(sprites->sprite_cursor, sprites->texture_cursor, sfTrue);
    sfSprite_setOrigin(sprites->sprite_cursor, origin);
    sfSprite_setPosition(sprites->sprite_cursor, coord);
    sfRenderWindow_drawSprite(window, sprites->sprite_cursor, NULL);
    if (hunter->play == 1 && sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (sfMusic_getStatus(hunter->shoot) == 0) {
            sfMusic_stop(hunter->shoot);
            sfMusic_play(hunter->shoot);
        }
    }
}