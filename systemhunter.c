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

void check_mouse(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    sfFloatRect posplay = {sfSprite_getPosition(sprites->s_boutonplay).x,
    sfSprite_getPosition(sprites->s_boutonplay).y, 144, 50};
    sfFloatRect quitplay = {sfSprite_getPosition(sprites->s_boutonquit).x,
    sfSprite_getPosition(sprites->s_boutonquit).y, 144, 50};
    float posmousex = sfMouse_getPositionRenderWindow(window).x;
    float posmousey = sfMouse_getPositionRenderWindow(window).y;
    hunter->playvalid = sfFloatRect_contains(&posplay, posmousex, posmousey);
    hunter->quitvalid = sfFloatRect_contains(&quitplay, posmousex, posmousey);
}

void play_bouton(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    sfSprite_setTexture(sprites->s_boutonplay, sprites->t_boutonplay, sfTrue);
    sfVector2f playboutonposition = {328, 200};
    sfSprite_setPosition(sprites->s_boutonplay, playboutonposition);
    sfRenderWindow_drawSprite(window, sprites->s_boutonplay, NULL);
}

void quit_bouton(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    sfSprite_setTexture(sprites->s_boutonquit, sprites->t_boutonquit, sfTrue);
    sfVector2f quitboutonposition = {328, 250};
    sfSprite_setPosition(sprites->s_boutonquit, quitboutonposition);
    sfRenderWindow_drawSprite(window, sprites->s_boutonquit, NULL);
}

void start_game(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites, sfEvent event)
{
    if (sfMusic_getStatus(hunter->music) == 0) {
        sfMusic_play(hunter->music);
        hunter->musicplayed = 1;
    }
    sfSprite_setTexture(sprites->s_bmenu, sprites->t_bmenu, sfTrue);
    sfRenderWindow_drawSprite(window, sprites->s_bmenu, NULL);
    sfSprite_setTexture(sprites->s_title, sprites->t_title, sfTrue);
    sfVector2f resizetitle = {0.30, 0.30};
    sfVector2f titleposition = {288, 50};
    sfSprite_setPosition(sprites->s_title, titleposition);
    sfSprite_setScale(sprites->s_title, resizetitle);
    sfRenderWindow_drawSprite(window, sprites->s_title, NULL);
    play_bouton(window, hunter, sprites);
    quit_bouton(window, hunter, sprites);
    check_mouse(window, hunter, sprites);
    if (hunter->playvalid == 1 && event.type == sfEvtMouseButtonPressed) {
        hunter->play = 1;
        hunter->musicplayed = 0;
        sfMusic_destroy(hunter->music);
        start_adog(window, hunter, sprites);
        start_adog2(window, hunter, sprites);
    } else if (hunter->quitvalid == 1 && event.type == sfEvtMouseButtonPressed) {
        sfMusic_destroy(hunter->music);
        sfRenderWindow_close(window);
    }
}