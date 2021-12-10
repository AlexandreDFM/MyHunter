/*
** EPITECH PROJECT, 2021
** setstructurehunter
** File description:
** Function to set sprites, textures & more for Hunter Game
*/

#include "./include/my.h"
#include "./include/myhunter.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>

void set_struct3(myhunter_t *hunter, sprite_t *sprite)
{
    sprite->t_jumpdog = sfTexture_createFromFile("./images/dogs_jump.png"
    , NULL);
    sprite->s_jumpdog = sfSprite_create();
    sprite->t_windog = sfTexture_createFromFile("./images/dogs_catch.png"
    , NULL);
    sprite->s_windog = sfSprite_create();
    sprite->t_cursor = sfTexture_createFromFile("./images/cursor.png", NULL);
    sprite->s_cursor = sfSprite_create();
}

void set_struct2(myhunter_t *hunter, sprite_t *sprite)
{
    sprite->t_b2 = sfTexture_createFromFile("./images/first_plan.png", NULL);
    sprite->s_b2 = sfSprite_create();
    sprite->t_shot = sfTexture_createFromFile("./images/shots.png", NULL);
    sprite->s_shot = sfSprite_create();
    sprite->t_shot2 = sfTexture_createFromFile("./images/shots.png", NULL);
    sprite->s_shot2 = sfSprite_create();
    sprite->t_hit = sfTexture_createFromFile("./images/hit_counter.png"
    , NULL);
    sprite->s_hit = sfSprite_create();
    sprite->t_hit2 = sfTexture_createFromFile("./images/hit_counter.png"
    , NULL);
    sprite->s_hit2 = sfSprite_create();
    sprite->t_basicdog = sfTexture_createFromFile("./images/dogs_walk.png"
    , NULL);
    sprite->s_basicdog = sfSprite_create();
    set_struct3(hunter, sprite);
}

void set_struct_decor_menus(myhunter_t *hunter, sprite_t *sprite)
{
    sprite->t_title = sfTexture_createFromFile("./images/title.png", NULL);
    sprite->s_title = sfSprite_create();
    sprite->t_bmenu = sfTexture_createFromFile("./images/background_menu.png"
    , NULL);
    sprite->s_bmenu = sfSprite_create();
    sprite->t_pause = sfTexture_createFromFile("./images/pause.png", NULL);
    sprite->s_pause = sfSprite_create();
    sprite->t_go = sfTexture_createFromFile("./images/game_over.png", NULL);
    sprite->s_go = sfSprite_create();
    sprite->t_boutonplay = sfTexture_createFromFile("./images/play_menu.png"
    , NULL);
    sprite->s_boutonplay = sfSprite_create();
    sprite->t_boutonquit = sfTexture_createFromFile("./images/quit_menu.png"
    , NULL);
    sprite->s_boutonquit = sfSprite_create();
    sprite->t_b1 = sfTexture_createFromFile("./images/background.png", NULL);
    sprite->s_b1 = sfSprite_create();
    set_struct2(hunter, sprite);
}

void set_struct_ducks(myhunter_t *hunter, sprite_t *sprite)
{
    int color = rand() % 9000;
    if (color <= 3000) {
        set_red_duck(hunter, sprite);
    } else if (color <= 6000) {
        set_blue_duck(hunter, sprite);
    } else {
        set_basic_duck(hunter, sprite);
    }
}

void set_struct(myhunter_t *hunter, sprite_t *sprite)
{
    int posy = rand() % 301;
    hunter->speeduck = 25;
    hunter->nbhit = 3;
    hunter->nbround = 1;
    hunter->nbtouchhit = 0;
    hunter->play = 0;
    set_struct4(hunter, sprite);
    set_struct5(hunter, sprite);
    set_struct_decor_menus(hunter, sprite);
    set_struct_ducks(hunter, sprite);
    hunter->music = sfMusic_createFromFile("./sounds/menu_music.ogg");
    hunter->shot = sfMusic_createFromFile("./sounds/sound_shot.ogg");
    hunter->winshot = sfMusic_createFromFile("./sounds/success_shot.ogg");
}
