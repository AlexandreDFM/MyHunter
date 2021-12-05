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

int display_b(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    sfVector2f resize = {3.136, 2.5};
    sfSprite_setTexture(sprites->s_b1, sprites->t_b1, sfTrue);
    sfSprite_setTextureRect(sprites->s_b1, hunter->rectback);
    sfSprite_setScale(sprites->s_b1, resize);
    sfRenderWindow_drawSprite(window, sprites->s_b1, NULL);
}

int display_shot(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    sfVector2f resize = {3.136, 2.5};
    sfSprite_setTexture(sprites->s_shot, sprites->t_shot, sfTrue);
    sfSprite_setTextureRect(sprites->s_shot, hunter->rectshot);
    sfSprite_setPosition(sprites->s_shot, hunter->positionshot);
    sfSprite_setScale(sprites->s_shot, resize);
    sfRenderWindow_drawSprite(window, sprites->s_shot, NULL);
    if (hunter->nbhit == 2) {
        hunter->rectshot2.width = 18;
    }
    if (hunter->nbhit == 1) {
        hunter->rectshot2.width = 9;
    }
    if (hunter->nbhit == 0) {
        hunter->rectshot2.width = 0;
    }
    sfSprite_setTexture(sprites->s_shot2, sprites->t_shot2, sfTrue);
    sfSprite_setTextureRect(sprites->s_shot2, hunter->rectshot2);
    sfSprite_setPosition(sprites->s_shot2, hunter->positionshot);
    sfSprite_setScale(sprites->s_shot2, resize);
    sfRenderWindow_drawSprite(window, sprites->s_shot2, NULL);
}

int display_hit(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    sfVector2f resize = {3.136, 2.5};
    sfSprite_setTexture(sprites->s_hit, sprites->t_hit, sfTrue);
    sfSprite_setTextureRect(sprites->s_hit, hunter->recthit);
    sfSprite_setPosition(sprites->s_hit, hunter->positionhit);
    sfSprite_setScale(sprites->s_hit, resize);
    sfRenderWindow_drawSprite(window, sprites->s_hit, NULL);
    sfSprite_setTexture(sprites->s_hit2, sprites->t_hit2, sfTrue);
    sfSprite_setTextureRect(sprites->s_hit2, hunter->recthit2);
    sfSprite_setPosition(sprites->s_hit2, hunter->positionhit);
    sfSprite_setScale(sprites->s_hit2, resize);
    sfRenderWindow_drawSprite(window, sprites->s_hit2, NULL);
}

int display_b2(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites)
{
    sfVector2f resize = {3.136, 2.5};
    sfSprite_setTexture(sprites->s_b2, sprites->t_b2, sfTrue);
    sfSprite_setTextureRect(sprites->s_b2, hunter->rectback);
    sfSprite_setScale(sprites->s_b2, resize);
    sfRenderWindow_drawSprite(window, sprites->s_b2, NULL);
    display_rnd(window, hunter, sprites);
    display_shot(window, hunter, sprites);
    display_hit(window, hunter, sprites);
    display_s(window, hunter, sprites);
}