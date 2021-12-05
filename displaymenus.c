/*
** EPITECH PROJECT, 2021
** displaymenus
** File description:
** Function display menu
*/

#include "./include/my.h"
#include "./include/myhunter.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>

int display_b(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfVector2f resize = {3.136, 2.5};
    sfSprite_setTexture(sprite->s_b1, sprite->t_b1, sfTrue);
    sfSprite_setTextureRect(sprite->s_b1, hunter->rectback);
    sfSprite_setScale(sprite->s_b1, resize);
    sfRenderWindow_drawSprite(window, sprite->s_b1, NULL);
}

int display_shot(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfVector2f resize = {3.136, 2.5};
    sfSprite_setTexture(sprite->s_shot, sprite->t_shot, sfTrue);
    sfSprite_setTextureRect(sprite->s_shot, hunter->rectshot);
    sfSprite_setPosition(sprite->s_shot, hunter->positionshot);
    sfSprite_setScale(sprite->s_shot, resize);
    sfRenderWindow_drawSprite(window, sprite->s_shot, NULL);
    if (hunter->nbhit == 2) {
        hunter->rectshot2.width = 18;
    }
    if (hunter->nbhit == 1) {
        hunter->rectshot2.width = 9;
    }
    if (hunter->nbhit == 0) {
        hunter->rectshot2.width = 0;
    }
    sfSprite_setTexture(sprite->s_shot2, sprite->t_shot2, sfTrue);
    sfSprite_setTextureRect(sprite->s_shot2, hunter->rectshot2);
    sfSprite_setPosition(sprite->s_shot2, hunter->positionshot);
    sfSprite_setScale(sprite->s_shot2, resize);
    sfRenderWindow_drawSprite(window, sprite->s_shot2, NULL);
}

int display_hit(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfVector2f resize = {3.136, 2.5};
    sfSprite_setTexture(sprite->s_hit, sprite->t_hit, sfTrue);
    sfSprite_setTextureRect(sprite->s_hit, hunter->recthit);
    sfSprite_setPosition(sprite->s_hit, hunter->positionhit);
    sfSprite_setScale(sprite->s_hit, resize);
    sfRenderWindow_drawSprite(window, sprite->s_hit, NULL);
    sfSprite_setTexture(sprite->s_hit2, sprite->t_hit2, sfTrue);
    sfSprite_setTextureRect(sprite->s_hit2, hunter->recthit2);
    sfSprite_setPosition(sprite->s_hit2, hunter->positionhit);
    sfSprite_setScale(sprite->s_hit2, resize);
    sfRenderWindow_drawSprite(window, sprite->s_hit2, NULL);
}

int display_b2(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfVector2f resize = {3.136, 2.5};
    sfSprite_setTexture(sprite->s_b2, sprite->t_b2, sfTrue);
    sfSprite_setTextureRect(sprite->s_b2, hunter->rectback);
    sfSprite_setScale(sprite->s_b2, resize);
    sfRenderWindow_drawSprite(window, sprite->s_b2, NULL);
    display_rnd(window, hunter, sprite);
    display_shot(window, hunter, sprite);
    display_hit(window, hunter, sprite);
    display_s(window, hunter, sprite);
}