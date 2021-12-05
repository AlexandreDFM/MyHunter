/*
** EPITECH PROJECT, 2021
** setstructurehunter2
** File description:
** Set Structure of Hunter Game
*/

#include "./include/my.h"
#include "./include/myhunter.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>

void set_red_duck(myhunter_t *hunter, sprite_t *sprites)
{
    sprites->t_basicduck = sfTexture_createFromFile(
            "./images/red_ducks.png", NULL);
    sprites->s_basicduck = sfSprite_create();
    sprites->t_fallduck = sfTexture_createFromFile(
            "./images/red_duck_fall.png", NULL);
    sprites->s_fallduck = sfSprite_create();
}

void set_blue_duck(myhunter_t *hunter, sprite_t *sprites)
{
    sprites->t_basicduck = sfTexture_createFromFile(
            "./images/blue_ducks.png", NULL);
        sprites->s_basicduck = sfSprite_create();
        sprites->t_fallduck = sfTexture_createFromFile(
            "./images/blue_duck_fall.png", NULL);
        sprites->s_fallduck = sfSprite_create();
}

void set_basic_duck(myhunter_t *hunter, sprite_t *sprites)
{
    sprites->t_basicduck = sfTexture_createFromFile(
            "./images/ducks.png", NULL);
    sprites->s_basicduck = sfSprite_create();
    sprites->t_fallduck = sfTexture_createFromFile(
            "./images/duck_fall.png", NULL);
    sprites->s_fallduck = sfSprite_create();
}

void set_struct4(myhunter_t *hunter, sprite_t *sprites)
{
    sfFont* font = sfFont_createFromFile("./police/8bit.ttf");
    hunter->font = font;
    sfIntRect recthit = {0, 0, 113, 18};
    hunter->recthit = recthit;
    sfIntRect recthit2 = {113, 0, 33, 18};
    hunter->recthit2 = recthit2;
    sfIntRect rectduck = {0, 0, 35, 42};
    hunter->rectduck = rectduck;
    sfIntRect rectduckfall = {0, 0, 35, 32};
    hunter->rectduckfall = rectduckfall;
    sfVector2f positionduck = {-42, rand() % 301};
    hunter->positionduck = positionduck;
    sfVector2f positionshot = {72, 517};
    hunter->positionshot = positionshot;
    sfVector2f positionhit = {197, 517};
    hunter->positionhit = positionhit;
    sfVector2f coordMouse = {0, 0};
    hunter->coordMouse = coordMouse;
}

void set_struct5(myhunter_t *hunter, sprite_t *sprites)
{
    sfClock *clock = sfClock_create();
    hunter->clock = clock;
    sfIntRect rectback = {0, 0, 255, 255};
    hunter->scorenb = 0;
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
}