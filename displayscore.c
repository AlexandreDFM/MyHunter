/*
** EPITECH PROJECT, 2021
** displayscore
** File description:
** Function display score
*/

#include "./include/my.h"
#include "./include/myhunter.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

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

char *make_score(myhunter_t *hunter)
{
    char *nb = my_put_nbrstr(hunter->scorenb);
    if (my_strlen(nb) < 6) {
        char *nb2 = malloc(sizeof(char)*7);
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

char *make_round(myhunter_t *hunter)
{
    char *nb = my_put_nbrstr(hunter->nbround);
    my_revstr(nb);
    char *nb2 = malloc(sizeof(char)* 2 + my_strlen(nb) + 1);
    char *round = "R=";
    int i = 0;
    for (; i < 2; i++)
        nb2[i] = round[i];
    for(int counter = 0; i < 2 + my_strlen(nb); i++, counter++)
        nb2[i] = nb[counter];
    nb2[i] = '\0';
    return (nb2);
}

int display_s(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfText_setString(hunter->score, make_score(hunter));
    sfText_setFont(hunter->score, hunter->font);
    sfText_setCharacterSize(hunter->score, 20);
    sfText_setPosition(hunter->score, hunter->positionscore);
    sfRenderWindow_drawText(window, hunter->score, NULL);
    sfText_setString(hunter->scoretext, "SCORE");
    sfText_setFont(hunter->scoretext, hunter->font);
    sfText_setCharacterSize(hunter->scoretext, 20);
    sfText_setPosition(hunter->scoretext, hunter->positionscoretext);
    sfRenderWindow_drawText(window, hunter->scoretext, NULL);
}

int display_rnd(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite)
{
    sfFont* font = sfFont_createFromFile("./police/8bit.ttf");
    sfText* text = sfText_create();
    sfVector2f position = {78, 482};
    sfText_setString(text, make_round(hunter));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 19);
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(window, text, NULL);
}