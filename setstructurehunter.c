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
    sprites->t_title = sfTexture_createFromFile("./images/Title.png", NULL);
    sprites->s_title = sfSprite_create();
    sprites->t_bmenu = sfTexture_createFromFile("./images/Background_Menu.png", NULL);
    sprites->s_bmenu = sfSprite_create();
    sprites->t_pause = sfTexture_createFromFile("./images/Pause.png", NULL);
    sprites->s_pause = sfSprite_create();
    sprites->t_go = sfTexture_createFromFile("./images/GameOver.png", NULL);
    sprites->s_go = sfSprite_create();
    sprites->t_boutonplay = sfTexture_createFromFile("./images/Play_Menu.png", NULL);
    sprites->s_boutonplay = sfSprite_create();
    sprites->t_boutonquit = sfTexture_createFromFile("./images/Quit_Menu.png", NULL);
    sprites->s_boutonquit = sfSprite_create();
    sprites->t_b1 = sfTexture_createFromFile("./images/Background.png", NULL);
    sprites->s_b1 = sfSprite_create();
    sprites->t_b2 = sfTexture_createFromFile("./images/First Plan.png", NULL);
    sprites->s_b2 = sfSprite_create();
    sprites->t_shot = sfTexture_createFromFile("./images/Shots.png", NULL);
    sprites->s_shot = sfSprite_create();
    sprites->t_shot2 = sfTexture_createFromFile("./images/Shots.png", NULL);
    sprites->s_shot2 = sfSprite_create();
    sprites->t_hit = sfTexture_createFromFile("./images/HitCounter.png", NULL);
    sprites->s_hit = sfSprite_create();
    sprites->t_hit2 = sfTexture_createFromFile("./images/HitCounter.png", NULL);
    sprites->s_hit2 = sfSprite_create();
}

void set_struct_animation(myhunter_t *hunter, sprite_t *sprites)
{
    int color = rand() % 9000;
    if (color <= 3000) {
        sprites->t_basicduck = sfTexture_createFromFile("./images/RedDucks.png", NULL);
        sprites->s_basicduck = sfSprite_create();
        sprites->t_fallduck = sfTexture_createFromFile("./images/RedDuckFall.png", NULL);
        sprites->s_fallduck = sfSprite_create();
    } else if (color <= 6000) {
        sprites->t_basicduck = sfTexture_createFromFile("./images/BlueDucks.png", NULL);
        sprites->s_basicduck = sfSprite_create();
        sprites->t_fallduck = sfTexture_createFromFile("./images/BlueDuckFall.png", NULL);
        sprites->s_fallduck = sfSprite_create();
    } else {
        sprites->t_basicduck = sfTexture_createFromFile("./images/Ducks.png", NULL);
        sprites->s_basicduck = sfSprite_create();
        sprites->t_fallduck = sfTexture_createFromFile("./images/DuckFall.png", NULL);
        sprites->s_fallduck = sfSprite_create();
    }
    sprites->t_cursor = sfTexture_createFromFile("./images/Cursor.png", NULL);
    sprites->s_cursor = sfSprite_create();
}

void set_struct(myhunter_t *hunter, sprite_t *sprites)
{
    int posy = rand() % 301;
    hunter->speeduck = 25;
    hunter->nbhit = 3;
    hunter->nbtouchhit = 0;
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
    sfIntRect rectshot = {0, 0, 26, 17};
    hunter->rectshot = rectshot;
    sfIntRect rectshot2 = {26, 0, 26, 17};
    hunter->rectshot2 = rectshot2;
    sfIntRect recthit = {0, 0, 113, 18};
    hunter->recthit = recthit;
    sfIntRect recthit2 = {113, 0, 33, 18};
    hunter->recthit2 = recthit2;
    sfIntRect rectduck = {0, 0, 35, 42};
    hunter->rectduck = rectduck;
    sfIntRect rectduckfall = {0, 0, 35, 32};
    hunter->rectduckfall = rectduckfall;
    sfVector2f positionduck = {-42, posy};
    hunter->positionduck = positionduck;
    sfVector2f positionshot = {72, 517};
    hunter->positionshot = positionshot;
    sfVector2f positionhit = {197, 517};
    hunter->positionhit = positionhit;
    sfVector2f coordMouse = {0, 0};
    hunter->coordMouse = coordMouse;
    set_struct_decor_menus(hunter, sprites);
    set_struct_animation(hunter, sprites);
    sprites->t_basicdog = sfTexture_createFromFile("./images/DogsWalk.png", NULL);
    sprites->s_basicdog = sfSprite_create();
    sprites->t_jumpdog = sfTexture_createFromFile("./images/DogsJump.png", NULL);
    sprites->s_jumpdog = sfSprite_create();
    hunter->music = sfMusic_createFromFile("./sounds/MenuMusic.ogg");
    hunter->shot = sfMusic_createFromFile("./sounds/SoundShot.ogg");
    hunter->winshot = sfMusic_createFromFile("./sounds/SuccessShot.ogg");
}