/*
** EPITECH PROJECT, 2021
** myhunter.h
** File description:
** MyHunter Lib & Struct
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct myhunter
{
    int play;
    int nbhit;
    int scorenb;
    int nbround;
    int speeduck;
    int playvalid;
    int quitvalid;
    int nbtouchhit;
    int duckonmouse;
    int musicplayed;
    int mouvementdogwin;
    sfEvent event;
    sfFont *font;
    sfText* score;
    sfText* scoretext;
    sfClock *clock;
    sfMusic *shot;
    sfMusic *music;
    sfMusic *winshot;
    sfIntRect rectback;
    sfIntRect rectshot;
    sfIntRect rectshot2;
    sfIntRect recthit;
    sfIntRect recthit2;
    sfIntRect rectduck;
    sfIntRect rectduckfall;
    sfVector2f coordMouse;
    sfVector2f positionhit;
    sfVector2f positionduck;
    sfVector2f positionshot;
    sfVector2f positionduckfall;
    sfVector2f positionscore;
    sfVector2f positiondogwin;
    sfVector2f positionscoretext;
} myhunter_t;

typedef struct sprite
{
    sfTexture* t_title;
    sfSprite* s_title;
    sfTexture* t_bmenu;
    sfSprite* s_bmenu;
    sfTexture* t_pause;
    sfSprite* s_pause;
    sfTexture* t_go;
    sfSprite* s_go;
    sfTexture* t_boutonplay;
    sfSprite* s_boutonplay;
    sfTexture* t_boutonquit;
    sfSprite* s_boutonquit;
    sfTexture* t_b1;
    sfSprite* s_b1;
    sfTexture* t_b2;
    sfSprite* s_b2;
    sfTexture* t_shot;
    sfSprite* s_shot;
    sfTexture* t_shot2;
    sfSprite* s_shot2;
    sfTexture* t_hit;
    sfSprite* s_hit;
    sfTexture* t_hit2;
    sfSprite* s_hit2;
    sfTexture* t_basicduck;
    sfSprite* s_basicduck;
    sfTexture* t_basicdog;
    sfSprite* s_basicdog;
    sfTexture* t_jumpdog;
    sfSprite* s_jumpdog;
    sfTexture* t_fallduck;
    sfSprite* s_fallduck;
    sfTexture* t_startdog;
    sfSprite* s_startdog;
    sfTexture* t_windog;
    sfSprite* s_windog;
    sfTexture* t_cursor;
    sfSprite* s_cursor;
} sprite_t;

#ifndef MY_HUNTER
    #define MY_HUNTER

int displaywindow(void);
void changehit(myhunter_t *hunter);
void play_sound(myhunter_t *hunter);
void clock_game(myhunter_t *hunter, sfIntRect *rect);
void set_struct(myhunter_t *hunter, sprite_t *sprite);
void set_struct4(myhunter_t *hunter, sprite_t *sprite);
void set_struct5(myhunter_t *hunter, sprite_t *sprite);
void set_red_duck(myhunter_t *hunter, sprite_t *sprite);
void set_blue_duck(myhunter_t *hunter, sprite_t *sprite);
void set_basic_duck(myhunter_t *hunter, sprite_t *sprite);
void destroy_struct(myhunter_t *hunter, sprite_t *sprite);
void move_rect(sfIntRect *rect, int offset, int max_value);
void mouvementduck(sfVector2f *positionduck, myhunter_t *hunter);
int cursor(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
void boucle(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
int display_b(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
int display_s(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
int display_b2(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
int start_adog(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
int check_shot(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
int start_adog2(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
int start_adog3(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
int start_fduck(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
int display_rnd(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
void start_game(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
void pause_game(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
void reset_duck(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
void check_mouse(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
void play_bouton(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
void quit_bouton(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);
int display_duck(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprite);

#endif
