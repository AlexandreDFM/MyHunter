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
#include <stdlib.h>

int displaybackground(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites)
{
    sfVector2f resize = {3.136, 2.5};
    sfSprite_setTexture(sprites->sprite_backgroundfirst, sprites->texture_backgroundfirst, sfTrue);
    sfSprite_setTextureRect(sprites->sprite_backgroundfirst, hunter->rectback);
    sfSprite_setScale(sprites->sprite_backgroundfirst, resize);
    sfRenderWindow_drawSprite(window, sprites->sprite_backgroundfirst, NULL);
}

int displaybackground2(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites)
{
    sfVector2f resize = {3.136, 2.5};
    sfSprite_setTexture(sprites->sprite_backgroundsecond, sprites->texture_backgroundsecond, sfTrue);
    sfSprite_setTextureRect(sprites->sprite_backgroundsecond, hunter->rectback);
    sfSprite_setScale(sprites->sprite_backgroundsecond, resize);
    sfRenderWindow_drawSprite(window, sprites->sprite_backgroundsecond, NULL);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left == max_value) {
        rect->left = 0;
    } else {
        rect->left += 35;
    }
}

int displaywindow(void)
{
    sfVideoMode mode = {800, 600, 32};                                                                                                                                     
    sfRenderWindow *window;
    sfEvent event;
    myhunter_t *hunter = malloc(sizeof(myhunter_t));
    sprite_t *sprites = malloc(sizeof(sprite_t));
    set_struct(hunter, sprites);
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible (window, sfFalse);
    //sfRenderWindow_setMouseCursorGrabbed(window, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            else if (sfKeyboard_isKeyPressed(sfKeyEscape) && hunter->play == 1)
                hunter->play = 2;
                //sfRenderWindow_close(window);
        }
        if (hunter->play == 0) {
            start_game(window, hunter, sprites, event);
            cursor(window, hunter, sprites);
        } else if (hunter->play == 2) {
            sfRenderWindow_clear(window, sfBlack);
            displaybackground(window, hunter, sprites);
            displayduck(window, hunter, sprites, event);
            displaybackground2(window, hunter, sprites);
            pause_game(window, hunter, sprites, event);
            cursor(window, hunter, sprites);
        } else {
            clock(hunter, &hunter->rectduck, 0, 105);
            sfRenderWindow_clear(window, sfBlack);
            displaybackground(window, hunter, sprites);
            displayduck(window, hunter, sprites, event);
            displaybackground2(window, hunter, sprites);
            cursor(window, hunter, sprites);
        }
        sfRenderWindow_display(window);
    }
}

int main(void)
{
    displaywindow();
}
