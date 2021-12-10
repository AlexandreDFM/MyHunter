/*
** EPITECH PROJECT, 2021
** destroystructurehunter
** File description:
** Destroy all struct
*/

#include "./include/my.h"
#include "./include/myhunter.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>

void destroy_struct_decor_menus(myhunter_t *hunter, sprite_t *sprite)
{
    sfTexture_destroy(sprite->t_title);
    sfSprite_destroy(sprite->s_title);
    sfTexture_destroy(sprite->t_bmenu);
    sfSprite_destroy(sprite->s_bmenu);
    sfTexture_destroy(sprite->t_boutonplay);
    sfSprite_destroy(sprite->s_boutonplay);
    sfTexture_destroy(sprite->t_boutonquit);
    sfSprite_destroy(sprite->s_boutonquit);
    sfTexture_destroy(sprite->t_b1);
    sfSprite_destroy(sprite->s_b1);
    sfTexture_destroy(sprite->t_b2);
    sfSprite_destroy(sprite->s_b2);
}

void destroy_struct_animation(myhunter_t *hunter, sprite_t *sprite)
{
    sfTexture_destroy(sprite->t_basicduck);
    sfSprite_destroy(sprite->s_basicduck);
    sfTexture_destroy(sprite->t_fallduck);
    sfSprite_destroy(sprite->s_fallduck);
    sfTexture_destroy(sprite->t_cursor);
    sfSprite_destroy(sprite->s_cursor);
}

void destroy_struct(myhunter_t *hunter, sprite_t *sprite)
{
    sfClock_destroy(hunter->clock);
    destroy_struct_decor_menus(hunter, sprite);
    destroy_struct_animation(hunter, sprite);
    sfMusic_destroy(hunter->shot);
    sfMusic_destroy(hunter->winshot);
    free(sprite);
}
