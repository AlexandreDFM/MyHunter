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
    int musicplayed;
    int mouvementdogwin;
    int scorenb;
    sfFont *font;
    sfText* score;
    sfText* scoretext;
    sfVector2f positionscore;
    sfVector2f positionscoretext;
    sfClock *clock;
    sfIntRect rectback;
    sfIntRect rectshoot;
    sfIntRect recthit;
    sfIntRect rectduck;
    sfVector2f positionduck;
    sfVector2f positionshoot;
    sfVector2f positionhit;
    sfVector2f coordMouse;
    sfMusic *music;
    sfMusic *shoot;
    sfMusic *winshoot;
} myhunter_t;

typedef struct sprite
{
    sfTexture* texture_title;
    sfSprite* sprite_title;
    sfTexture* texture_backgroundmenu;
    sfSprite* sprite_backgroundmenu;
    sfTexture* texture_boutonplay;
    sfSprite* sprite_boutonplay;
    sfTexture* texture_boutonquit;
    sfSprite* sprite_boutonquit;
    sfTexture* texture_backgroundfirst;
    sfSprite* sprite_backgroundfirst;
    sfTexture* texture_backgroundsecond;
    sfSprite* sprite_backgroundsecond;
    sfTexture* texture_shoot;
    sfSprite* sprite_shoot;
    sfTexture* texture_hit;
    sfSprite* sprite_hit;
    sfTexture* texture_basicduck;
    sfSprite* sprite_basicduck;
    sfTexture* texture_fallduck;
    sfSprite* sprite_fallduck;
    sfTexture* texture_startdog;
    sfSprite* sprite_startdog;
    sfTexture* texture_windog;
    sfSprite* sprite_windog;
    sfTexture* texture_cursor;
    sfSprite* sprite_cursor;
} sprite_t;

#ifndef MY_HUNTER
    #define MY_HUNTER

void set_struct(myhunter_t *hunter, sprite_t *sprites);
void start_game(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites, sfEvent event);
void pause_game(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites, sfEvent event);
int displaybackground(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites);
int displaybackground2(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites);
void move_rect(sfIntRect *rect, int offset, int max_value);
void clock_game(myhunter_t *hunter, sfIntRect *rect, int offset, int max_value);
void mouvementduck(sfVector2f *positionduck);
int displayduck(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites, sfEvent event);
int cursor(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites, sfEvent event);
int displaywindow(void);
int start_animation_dog(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites);
int start_animation_dog2(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites);
int start_animation_dog3(sfRenderWindow *window, myhunter_t *hunter, sprite_t *sprites, sfVector2f positionduck);
int display_duck_fall(sfRenderWindow *window, struct myhunter *hunter, sprite_t *sprites, sfVector2f positionduck);
void destroy_struct(myhunter_t *hunter, sprite_t *sprites);

#endif /* !MY_HUNTER */