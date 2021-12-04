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

void set_struct_decor_menus(myhunter_t *hunter, sprite_t *sprites)
{
    sprites->texture_title = sfTexture_createFromFile("./images/Title.png", NULL);
    sprites->sprite_title = sfSprite_create();
    sprites->texture_backgroundmenu = sfTexture_createFromFile("./images/Background_Menu.png", NULL);
    sprites->sprite_backgroundmenu = sfSprite_create();
    sprites->texture_boutonplay = sfTexture_createFromFile("./images/Play_Menu.png", NULL);
    sprites->sprite_boutonplay = sfSprite_create();
    sprites->texture_boutonquit = sfTexture_createFromFile("./images/Quit_Menu.png", NULL);
    sprites->sprite_boutonquit = sfSprite_create();
    sprites->texture_backgroundfirst = sfTexture_createFromFile("./images/Background.png", NULL);
    sprites->sprite_backgroundfirst = sfSprite_create();
    sprites->texture_backgroundsecond = sfTexture_createFromFile("./images/First Plan.png", NULL);
    sprites->sprite_backgroundsecond = sfSprite_create();
    sprites->texture_shoot = sfTexture_createFromFile("./images/Shots.png", NULL);
    sprites->sprite_shoot = sfSprite_create();
    sprites->texture_hit = sfTexture_createFromFile("./images/HitCounter.png", NULL);
    sprites->sprite_hit = sfSprite_create();
}

void set_struct_animation(myhunter_t *hunter, sprite_t *sprites)
{
    int color = rand() % 9000;
    if (color <= 3000) {
        sprites->texture_basicduck = sfTexture_createFromFile("./images/RedDucks.png", NULL);
        sprites->sprite_basicduck = sfSprite_create();
        sprites->texture_fallduck = sfTexture_createFromFile("./images/RedDuckFall.png", NULL);
        sprites->sprite_fallduck = sfSprite_create();
    } else if (color <= 6000) {
        sprites->texture_basicduck = sfTexture_createFromFile("./images/BlueDucks.png", NULL);
        sprites->sprite_basicduck = sfSprite_create();
        sprites->texture_fallduck = sfTexture_createFromFile("./images/BlueDuckFall.png", NULL);
        sprites->sprite_fallduck = sfSprite_create();
    } else {
        sprites->texture_basicduck = sfTexture_createFromFile("./images/Ducks.png", NULL);
        sprites->sprite_basicduck = sfSprite_create();
        sprites->texture_fallduck = sfTexture_createFromFile("./images/DuckFall.png", NULL);
        sprites->sprite_fallduck = sfSprite_create();
    }
    sprites->texture_cursor = sfTexture_createFromFile("./images/Cursor.png", NULL);
    sprites->sprite_cursor = sfSprite_create();
}

void set_struct(myhunter_t *hunter, sprite_t *sprites)
{
    int posy = rand() % 301;
    hunter->play = 0;
    sfClock *clock = sfClock_create();
    hunter->clock = clock;
    sfIntRect rectback = {0, 0, 255, 255};

    hunter->scorenb = 0;
    sfFont* font = sfFont_createFromFile("./police/8bit.ttf");
    hunter->font = font;
    sfText* score = sfText_create();
    hunter->score = score;
    sfVector2f positionscore = {602, 520};
    hunter->positionscore = positionscore;
    
    sfText* scoretext = sfText_create();
    hunter->scoretext = scoretext;
    sfVector2f positionscoretext = {623, 542};
    hunter->positionscoretext = positionscoretext;

    hunter->rectback = rectback;
    sfIntRect rectshoot = {0, 0, 26, 17};
    hunter->rectshoot = rectshoot;
    sfIntRect recthit = {0, 0, 113, 18};
    hunter->recthit = recthit;
    sfIntRect rectduck = {0, 0, 35, 42};
    hunter->rectduck = rectduck;
    sfVector2f positionduck = {-42, posy};
    hunter->positionduck = positionduck;
    sfVector2f positionshoot = {72, 517};
    hunter->positionshoot = positionshoot;
    sfVector2f positionhit = {197, 517};
    hunter->positionhit = positionhit;
    sfVector2f coordMouse = {0, 0};
    hunter->coordMouse = coordMouse;
    set_struct_decor_menus(hunter, sprites);
    set_struct_animation(hunter, sprites);
    hunter->music = sfMusic_createFromFile("./sounds/MenuMusic.ogg");
    hunter->shoot = sfMusic_createFromFile("./sounds/SoundShoot.ogg");
    hunter->winshoot = sfMusic_createFromFile("./sounds/SuccessShoot.ogg");
}