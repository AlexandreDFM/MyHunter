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

void set_struct3(myhunter_t *hunter, sprite_t *sprites)
{
    sprites->t_jumpdog = sfTexture_createFromFile("./images/dogs_jump.png"
    , NULL);
    sprites->s_jumpdog = sfSprite_create();
    sprites->t_windog = sfTexture_createFromFile("./images/dogs_catch.png"
    , NULL);
    sprites->s_windog = sfSprite_create();
    sprites->t_cursor = sfTexture_createFromFile("./images/cursor.png", NULL);
    sprites->s_cursor = sfSprite_create();
}

void set_struct2(myhunter_t *hunter, sprite_t *sprites)
{
    sprites->t_b2 = sfTexture_createFromFile("./images/first_plan.png", NULL);
    sprites->s_b2 = sfSprite_create();
    sprites->t_shot = sfTexture_createFromFile("./images/shots.png", NULL);
    sprites->s_shot = sfSprite_create();
    sprites->t_shot2 = sfTexture_createFromFile("./images/shots.png", NULL);
    sprites->s_shot2 = sfSprite_create();
    sprites->t_hit = sfTexture_createFromFile("./images/hit_counter.png"
    , NULL);
    sprites->s_hit = sfSprite_create();
    sprites->t_hit2 = sfTexture_createFromFile("./images/hit_counter.png"
    , NULL);
    sprites->s_hit2 = sfSprite_create();
    sprites->t_basicdog = sfTexture_createFromFile("./images/dogs_walk.png"
    , NULL);
    sprites->s_basicdog = sfSprite_create();
    set_struct3(hunter, sprites);
}

void set_struct_decor_menus(myhunter_t *hunter, sprite_t *sprites)
{
    sprites->t_title = sfTexture_createFromFile("./images/title.png", NULL);
    sprites->s_title = sfSprite_create();
    sprites->t_bmenu = sfTexture_createFromFile("./images/background_menu.png"
    , NULL);
    sprites->s_bmenu = sfSprite_create();
    sprites->t_pause = sfTexture_createFromFile("./images/pause.png", NULL);
    sprites->s_pause = sfSprite_create();
    sprites->t_go = sfTexture_createFromFile("./images/game_over.png", NULL);
    sprites->s_go = sfSprite_create();
    sprites->t_boutonplay = sfTexture_createFromFile("./images/play_menu.png"
    , NULL);
    sprites->s_boutonplay = sfSprite_create();
    sprites->t_boutonquit = sfTexture_createFromFile("./images/quit_menu.png"
    , NULL);
    sprites->s_boutonquit = sfSprite_create();
    sprites->t_b1 = sfTexture_createFromFile("./images/background.png", NULL);
    sprites->s_b1 = sfSprite_create();
    set_struct2(hunter, sprites);
}

void set_struct_ducks(myhunter_t *hunter, sprite_t *sprites)
{
    int color = rand() % 9000;
    if (color <= 3000) {
        set_red_duck(hunter, sprites);
    } else if (color <= 6000) {
        set_blue_duck(hunter, sprites);
    } else {
        set_basic_duck(hunter, sprites);
    }
}

void set_struct(myhunter_t *hunter, sprite_t *sprites)
{
    int posy = rand() % 301;
    hunter->speeduck = 25;
    hunter->nbhit = 3;
    hunter->nbround = 1;
    hunter->nbtouchhit = 0;
    hunter->play = 0;
    set_struct4(hunter, sprites);
    set_struct5(hunter, sprites);
    set_struct_decor_menus(hunter, sprites);
    set_struct_ducks(hunter, sprites);
    hunter->music = sfMusic_createFromFile("./sounds/MenuMusic.ogg");
    hunter->shot = sfMusic_createFromFile("./sounds/SoundShot.ogg");
    hunter->winshot = sfMusic_createFromFile("./sounds/SuccessShot.ogg");
}