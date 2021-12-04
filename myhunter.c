/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** Reproduce the duck hunt game
*/

#include "./include/my.h"
#include "./include/myhunter.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>

int displaybackground(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites)
{
    sfVector2f resize = {3.136, 2.5};
    sfSprite_setTexture(sprites->sprite_backgroundfirst, sprites->texture_backgroundfirst, sfTrue);
    sfSprite_setTextureRect(sprites->sprite_backgroundfirst, hunter->rectback);
    sfSprite_setScale(sprites->sprite_backgroundfirst, resize);
    sfRenderWindow_drawSprite(window, sprites->sprite_backgroundfirst, NULL);
}

int displayround(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites)
{
    sfFont* font = sfFont_createFromFile("./police/8bit.ttf");
    sfText* text = sfText_create();
    sfVector2f position = {78, 482};
    sfText_setString(text, "R=1");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 19);
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(window, text, NULL);
}

int displayshoot(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites)
{
    sfVector2f resize = {3.136, 2.5};
    sfSprite_setTexture(sprites->sprite_shoot, sprites->texture_shoot, sfTrue);
    sfSprite_setTextureRect(sprites->sprite_shoot, hunter->rectshoot);
    sfSprite_setPosition(sprites->sprite_shoot, hunter->positionshoot);
    sfSprite_setScale(sprites->sprite_shoot, resize);
    sfRenderWindow_drawSprite(window, sprites->sprite_shoot, NULL);
}

int displayhit(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites)
{
    sfVector2f resize = {3.136, 2.5};
    sfSprite_setTexture(sprites->sprite_hit, sprites->texture_hit, sfTrue);
    sfSprite_setTextureRect(sprites->sprite_hit, hunter->recthit);
    sfSprite_setPosition(sprites->sprite_hit, hunter->positionhit);
    sfSprite_setScale(sprites->sprite_hit, resize);
    sfRenderWindow_drawSprite(window, sprites->sprite_hit, NULL);
}

char *my_put_nbrstr(int number)
{
    int number2, i = 0;
    char *str = malloc(sizeof(char)*10);
    for (; number > 0;) {
        if (number >= 10) {
            number2 = number % 10;
            number = (number - number2) / 10;
            str[i] = number2 + 48;
            i += 1;
        } else {
            str[i] = number + 48;
            i += 1;
            number = 0;
        }
    }
    str[i] = '\0';
    return (str);
}

char *make_score(struct myhunter *hunter)
{
    char *nb = my_put_nbrstr(hunter->scorenb);
    if (my_strlen(nb) < 6) {
        char *nb2 = malloc(sizeof(char)*6);
        int i = 0;
        for (; i < my_strlen(nb); i++)
            nb2[i] = nb[i];
        for(; i < 6; i++)
            nb2[i] = '0';
        nb2[i] = '\0';
        my_revstr(nb2);
        return (nb2);
    } else if (my_strlen(nb) > 6) {
        hunter->scorenb = 0;
        return ("000000");
    }
    return (my_revstr(nb));
}

int displayscore(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites)
{
    //sfFont* font = sfFont_createFromFile("./police/8bit.ttf");
    //sfText* score = sfText_create();
    //sfVector2f position = {602, 520};
    //printf("%s\n", my_put_nbrstr(10));
    sfText_setString(hunter->score, make_score(hunter));
    sfText_setFont(hunter->score, hunter->font);
    sfText_setCharacterSize(hunter->score, 20);
    sfText_setPosition(hunter->score, hunter->positionscore);
    sfRenderWindow_drawText(window, hunter->score, NULL);

    //sfText* scoretext = sfText_create();
    //sfVector2f position2 = {623, 542};
    sfText_setString(hunter->scoretext, "SCORE");
    sfText_setFont(hunter->scoretext, hunter->font);
    sfText_setCharacterSize(hunter->scoretext, 20);
    sfText_setPosition(hunter->scoretext, hunter->positionscoretext);
    sfRenderWindow_drawText(window, hunter->scoretext, NULL);
}

int displaybackground2(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites)
{
    sfVector2f resize = {3.136, 2.5};
    sfSprite_setTexture(sprites->sprite_backgroundsecond, sprites->texture_backgroundsecond, sfTrue);
    sfSprite_setTextureRect(sprites->sprite_backgroundsecond, hunter->rectback);
    sfSprite_setScale(sprites->sprite_backgroundsecond, resize);
    sfRenderWindow_drawSprite(window, sprites->sprite_backgroundsecond, NULL);
    displayround(window, hunter, sprites);
    displayshoot(window, hunter, sprites);
    displayhit(window, hunter, sprites);
    displayscore(window, hunter, sprites);
}

int displaywindow(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfEvent event;
    myhunter_t *hunter = malloc(sizeof(myhunter_t));
    sprite_t *sprites = malloc(sizeof(sprite_t));
    set_struct(hunter, sprites);
    window = sfRenderWindow_create(mode, "My_Hunter", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible (window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyBackspace))
                sfRenderWindow_close(window);
            else if (sfKeyboard_isKeyPressed(sfKeyEscape) && hunter->play == 1)
                hunter->play = 2;
        }
        if (hunter->play == 0) {
            sfRenderWindow_setMouseCursorGrabbed(window, sfFalse);
            start_game(window, hunter, sprites, event);
            cursor(window, hunter, sprites, event);
        } else if (hunter->play == 2) {
            sfRenderWindow_setMouseCursorGrabbed(window, sfFalse);
            sfRenderWindow_clear(window, sfBlack);
            displaybackground(window, hunter, sprites);
            displayduck(window, hunter, sprites, event);
            displaybackground2(window, hunter, sprites);
            pause_game(window, hunter, sprites, event);
            cursor(window, hunter, sprites, event);
        } else {
            sfRenderWindow_setMouseCursorGrabbed(window, sfTrue);
            clock_game(hunter, &hunter->rectduck, 0, 105);
            sfRenderWindow_clear(window, sfBlack);
            displaybackground(window, hunter, sprites);
            displayduck(window, hunter, sprites, event);
            displaybackground2(window, hunter, sprites);
            cursor(window, hunter, sprites, event);
        }
        sfRenderWindow_display(window);
    }
    destroy_struct(hunter, sprites);
}

int main(void)
{
    srand(time(0));
    displaywindow();
}
