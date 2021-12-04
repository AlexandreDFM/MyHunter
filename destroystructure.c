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
    sfTexture_destroy(sprites->texture_title);
    sfSprite_destroy(sprites->sprite_title);
    sfTexture_destroy(sprites->texture_backgroundmenu);
    sfSprite_destroy(sprites->sprite_backgroundmenu);
    sfTexture_destroy(sprites->texture_boutonplay);
    sfSprite_destroy(sprites->sprite_boutonplay);
    sfTexture_destroy(sprites->texture_boutonquit);
    sfSprite_destroy(sprites->sprite_boutonquit);
    sfTexture_destroy(sprites->texture_backgroundfirst);
    sfSprite_destroy(sprites->sprite_backgroundfirst);
    sfTexture_destroy(sprites->texture_backgroundsecond);
    sfSprite_destroy(sprites->sprite_backgroundsecond);
}

void destroy_struct_animation(myhunter_t *hunter, sprite_t *sprites)
{
    sfTexture_destroy(sprites->texture_basicduck);
    sfSprite_destroy(sprites->sprite_basicduck);
    sfTexture_destroy(sprites->texture_fallduck);
    sfSprite_destroy(sprites->sprite_fallduck);
    sfTexture_destroy(sprites->texture_cursor);
    sfSprite_destroy(sprites->sprite_cursor);
}

void destroy_struct(myhunter_t *hunter, sprite_t *sprites)
{
    sfClock_destroy(hunter->clock);
    destroy_struct_decor_menus(hunter, sprites);
    destroy_struct_animation(hunter, sprites);
    sfMusic_destroy(hunter->shoot);
    sfMusic_destroy(hunter->winshoot);
    free(hunter);
    free(sprites);
}