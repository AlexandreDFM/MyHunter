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

void manage_mouse_click(sfMouseButtonEvent event, struct myhunter *hunter)
{
    my_putstr("Mouse x=");
    my_put_nbr(event.x);
    my_putstr(" y=");
    my_put_nbr(event.y);
    my_putchar('\n');
    hunter->coordMouse.x = event.x;
    hunter->coordMouse.y = event.y;
}

void analyse_events(sfRenderWindow *window, sfEvent event, struct myhunter *hunter)
{
    if (event.type == sfEvtMouseButtonPressed) {
        manage_mouse_click(event.mouseButton, &hunter);
    }
}

int displaybackground(sfRenderWindow *window, struct myhunter *hunter)
{
    sfTexture* texture;
    sfSprite* sprite;
    //sfIntRect rect = {0, 0, 255, 255};
    sfVector2f resize = {3.136, 2.5};
    texture = sfTexture_createFromFile("./images/Backgrounds.png", NULL);
    if (!texture)
        return (84);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, hunter->rectback);
    sfSprite_setScale(sprite, resize);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left == max_value) {
        rect->left = 0;
    } else {
        rect->left += 35;
    }
}

void clockduck(sfIntRect *rect, int offset, int max_value)
{
    sfClock *clock;
    sfTime time;
    float seconds;
    clock = sfClock_create();
    int i = 0;
    while (i != 1) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 100000.0;
        if (seconds > 1.0) {
            move_rect(rect, 0, 70);
            sfClock_restart(clock);
            i += 1;
        }
    }
}

void mouvementduck(sfVector2f *positionduck)
{
    positionduck->x += 5;
    if (positionduck->x == 835 || positionduck->x == -35) {
        positionduck->x = -34;
    } else if (positionduck->y == 642 || positionduck->y == -42) {
        positionduck->y = -41;
    }
}

int displayduck(sfRenderWindow *window, struct myhunter *hunter)
{
    sfTexture* texture;
    sfSprite* sprite;
    sfEvent event;
    //sfIntRect rect = {0, 0, 35, 42};
    sfVector2f resize = {3, 3};
    texture = sfTexture_createFromFile("./images/Ducks.png", NULL);
    if (!texture)
        return (84);
    analyse_events(window, event, &hunter);
    sfVector2f temp = sfSprite_getPosition(sprite);
    //if (temp.x == hunter->coordMouse.x && temp.y == hunter->coordMouse.y)
    //    my_put_nbr(1000);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    //move_rect(&hunter->rectduck, 0, 105);
    clockduck(&hunter->rectduck, 0, 105);
    sfSprite_setTextureRect(sprite, hunter->rectduck);
    sfSprite_setPosition(sprite, hunter->positionduck);
    mouvementduck(&hunter->positionduck);
    sfSprite_setScale(sprite, resize);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

int displaywindow(void)
{
    sfVideoMode mode = {800, 600, 32};                                                                                                                                     
    sfRenderWindow *window;
    sfEvent event;
    struct myhunter hunter = {{0, 0, 255, 255}, {0, 0, 35, 42}, {0, -34}, {0,0}};
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!window)                                                                                                                                                                              
        return (84);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
                sfRenderWindow_close(window);
                analyse_events(window, event, &hunter);
        }
        sfRenderWindow_clear(window, sfBlack);
        displaybackground(window, &hunter);
        displayduck(window, &hunter);
        sfRenderWindow_display(window);
    }
}

int main(void)
{
    displaywindow();
}