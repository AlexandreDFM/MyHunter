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

int display_window(myhunter_t *hunter)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sprite_t *sprite = malloc(sizeof(sprite_t));
    set_struct(hunter, sprite);
    char *name = "MyHunter Project";
    window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible (window, sfFalse);
    boucle(window, hunter, sprite);
    if (window) {
        sfRenderWindow_close(window);
    }
    destroy_struct(hunter, sprite);
}

void print_manual(void)
{
    my_putstr("\n                                                  DUCK "
                "HUNT\n\n");
    my_putstr("Duck Hunt is a shooter game in which the objective is to "
                "shoot moving targets on the screen in "
                "mid-flight.\n");
    my_putstr("The ducks will move faster each rounds.\n");
    my_putstr("\n                                                  RULES\n\n");
    my_putstr("Shoot 10 ducks to pass the round or you'll game over if you "
                "fail 3 hit, hit a duck is 100 pts.\n");
    my_putstr("\n                                                  "
                "CONTROLS\n\n");
    my_putstr("      - Click on the play bouton to start or exit bouton to "
                "exit.\n");
    my_putstr("      - Once in game press escape to pause.\n");
    my_putstr("      - If paused press space or click on the play bouton to "
                "resume, you can also click on the exit bouton to exit.\n");
    my_putstr("      - Aim by moving your mouse and shoot the ducks with "
                "your left mouse button.\n\n");
}

int main(int argc, char **argv)
{
    myhunter_t *hunter = malloc(sizeof(myhunter_t));
    hunter->play = 0;
    if (argc == 1) {
        srand(time(0));
        display_window(hunter);
    } else if (argc == 2 && my_strlen(argv[1]) == 2 && argv[1][0] == '-'
    && argv[1][1] == 'h') {
        print_manual();
    }
    if (hunter->play == 4) {
        while (hunter->play == 4) {
            display_window(hunter);
        }
    }
    free(hunter);
    return (0);
}