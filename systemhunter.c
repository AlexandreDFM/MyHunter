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

void check_mouse(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfFloatRect posplay = {sfSprite_getPosition(sprite->s_boutonplay).x,
    sfSprite_getPosition(sprite->s_boutonplay).y, 144, 50};
    sfFloatRect quitplay = {sfSprite_getPosition(sprite->s_boutonquit).x,
    sfSprite_getPosition(sprite->s_boutonquit).y, 144, 50};
    float posmousex = sfMouse_getPositionRenderWindow(window).x;
    float posmousey = sfMouse_getPositionRenderWindow(window).y;
    hunter->playvalid = sfFloatRect_contains(&posplay, posmousex, posmousey);
    hunter->quitvalid = sfFloatRect_contains(&quitplay, posmousex, posmousey);
}

void play_bouton(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfSprite_setTexture(sprite->s_boutonplay, sprite->t_boutonplay, sfTrue);
    sfVector2f playboutonposition = {328, 200};
    sfSprite_setPosition(sprite->s_boutonplay, playboutonposition);
    sfRenderWindow_drawSprite(window, sprite->s_boutonplay, NULL);
}

void quit_bouton(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfSprite_setTexture(sprite->s_boutonquit, sprite->t_boutonquit, sfTrue);
    sfVector2f quitboutonposition = {328, 250};
    sfSprite_setPosition(sprite->s_boutonquit, quitboutonposition);
    sfRenderWindow_drawSprite(window, sprite->s_boutonquit, NULL);
}

void check_valid(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    if (hunter->playvalid == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        hunter->play = 1;
        hunter->musicplayed = 0;
        sfMusic_destroy(hunter->music);
        start_adog(window, hunter, sprite);
        start_adog2(window, hunter, sprite);
    }
    else if (hunter->quitvalid == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_destroy(hunter->music);
        sfRenderWindow_close(window);
    }
}

void start_game(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    if (sfMusic_getStatus(hunter->music) == 0) {
        sfMusic_play(hunter->music);
        hunter->musicplayed = 1;
    }
    sfSprite_setTexture(sprite->s_bmenu, sprite->t_bmenu, sfTrue);
    sfRenderWindow_drawSprite(window, sprite->s_bmenu, NULL);
    sfSprite_setTexture(sprite->s_title, sprite->t_title, sfTrue);
    sfVector2f resizetitle = {0.30, 0.30};
    sfVector2f titleposition = {288, 50};
    sfSprite_setPosition(sprite->s_title, titleposition);
    sfSprite_setScale(sprite->s_title, resizetitle);
    sfRenderWindow_drawSprite(window, sprite->s_title, NULL);
    play_bouton(window, hunter, sprite);
    quit_bouton(window, hunter, sprite);
    check_mouse(window, hunter, sprite);
    check_valid(window, hunter, sprite);
}
