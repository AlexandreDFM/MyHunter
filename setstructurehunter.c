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
#include <stdlib.h>

void set_struct(myhunter_t *hunter, sprite_t *sprites)
{
    hunter->play = 0;
    sfClock *clock = sfClock_create();
    hunter->clock = clock;
    sfIntRect rectback = {0, 0, 255, 255};
    hunter->rectback = rectback;
    sfIntRect rectduck = {0, 0, 35, 42};
    hunter->rectduck = rectduck;
    sfVector2f positionduck = {-42, 0};
    hunter->positionduck = positionduck;
    sfVector2f coordMouse = {0,0};
    hunter->coordMouse = coordMouse;
    sprites->texture_title = sfTexture_createFromFile("./images/DuckHunt/Title.png", NULL);
    sprites->sprite_title = sfSprite_create();
    sprites->texture_backgroundmenu = sfTexture_createFromFile("./images/DuckHunt/Background_Menu.png", NULL);
    sprites->sprite_backgroundmenu = sfSprite_create();
    sprites->texture_boutonplay = sfTexture_createFromFile("./images/DuckHunt/Play_Menu.png", NULL);
    sprites->sprite_boutonplay = sfSprite_create();
    sprites->texture_boutonquit = sfTexture_createFromFile("./images/DuckHunt/Quit_Menu.png", NULL);
    sprites->sprite_boutonquit = sfSprite_create();
    sprites->texture_backgroundfirst = sfTexture_createFromFile("./images/DuckHunt/Background.png", NULL);
    sprites->sprite_backgroundfirst = sfSprite_create();
    sprites->texture_backgroundsecond = sfTexture_createFromFile("./images/DuckHunt/First Plan.png", NULL);
    sprites->sprite_backgroundsecond = sfSprite_create();
    sprites->texture_basicduck = sfTexture_createFromFile("./images/Ducks.png", NULL);
    sprites->sprite_basicduck = sfSprite_create();
    sprites->texture_fallduck = sfTexture_createFromFile("./images/DuckHunt/DuckFall.png", NULL);
    sprites->sprite_fallduck = sfSprite_create();
    sprites->texture_cursor = sfTexture_createFromFile("./images/DuckHunt/Cursor.png", NULL);
    sprites->sprite_cursor = sfSprite_create();
}