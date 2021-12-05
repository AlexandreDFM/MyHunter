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

void close_window(sfRenderWindow *window, myhunter_t *hunter, sfEvent event)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyBackspace))
        sfRenderWindow_close(window);
    else if (sfKeyboard_isKeyPressed(sfKeyEscape) && hunter->play == 1)
        hunter->play = 2;
}

void launch_game(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfRenderWindow_setMouseCursorGrabbed(window, sfFalse);
    start_game(window, hunter, sprite);
    cursor(window, hunter, sprite);
}

void stop_game(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfRenderWindow_setMouseCursorGrabbed(window, sfFalse);
    sfRenderWindow_clear(window, sfBlack);
    display_b(window, hunter, sprite);
    display_duck(window, hunter, sprite);
    display_b2(window, hunter, sprite);
    pause_game(window, hunter, sprite);
    cursor(window, hunter, sprite);
}

void game(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfRenderWindow_setMouseCursorGrabbed(window, sfTrue);
    clock_game(hunter, &hunter->rectduck);
    sfRenderWindow_clear(window, sfBlack);
    display_b(window, hunter, sprite);
    display_duck(window, hunter, sprite);
    display_b2(window, hunter, sprite);
    cursor(window, hunter, sprite);
    check_shot(window, hunter, sprite);
}

void boucle(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfEvent event;
    while (sfRenderWindow_isOpen(window) && hunter->play < 4) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            close_window(window, hunter, event);
        }
        if (hunter->play == 0) {
            hunter->event = event;
            launch_game(window, hunter, sprite);
        } else if (hunter->play == 2) {
            hunter->event = event;
            stop_game(window, hunter, sprite);
        } else {
            hunter->event = event;
            game(window, hunter, sprite);
        }
        sfRenderWindow_display(window);
    }
}