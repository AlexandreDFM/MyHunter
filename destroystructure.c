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

void destroy_struct_decor_menus(myhunter_t *hunter, sprite_t *sprites)
{
    sfTexture_destroy(sprites->t_title);
    sfSprite_destroy(sprites->s_title);
    sfTexture_destroy(sprites->t_bmenu);
    sfSprite_destroy(sprites->s_bmenu);
    sfTexture_destroy(sprites->t_boutonplay);
    sfSprite_destroy(sprites->s_boutonplay);
    sfTexture_destroy(sprites->t_boutonquit);
    sfSprite_destroy(sprites->s_boutonquit);
    sfTexture_destroy(sprites->t_b1);
    sfSprite_destroy(sprites->s_b1);
    sfTexture_destroy(sprites->t_b2);
    sfSprite_destroy(sprites->s_b2);
}

void destroy_struct_animation(myhunter_t *hunter, sprite_t *sprites)
{
    sfTexture_destroy(sprites->t_basicduck);
    sfSprite_destroy(sprites->s_basicduck);
    sfTexture_destroy(sprites->t_fallduck);
    sfSprite_destroy(sprites->s_fallduck);
    sfTexture_destroy(sprites->t_cursor);
    sfSprite_destroy(sprites->s_cursor);
}

void destroy_struct(myhunter_t *hunter, sprite_t *sprites)
{
    sfClock_destroy(hunter->clock);
    destroy_struct_decor_menus(hunter, sprites);
    destroy_struct_animation(hunter, sprites);
    sfMusic_destroy(hunter->shot);
    sfMusic_destroy(hunter->winshot);
    free(sprites);
}