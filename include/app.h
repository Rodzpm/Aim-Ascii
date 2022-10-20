/*
** EPITECH PROJECT, 2022
** app
** File description:
** app.h file
*/
#pragma once
#include <SFML/Graphics.h>
#include <stdbool.h>
#include <SFML/Window/Export.h>

typedef struct system{
    sfRenderWindow *window;
    bool in_menu;
    bool in_end;
    int score;
    int sec;
} sys_t;

typedef struct image{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    void (*update)(struct image *img, sfRenderWindow *window, float scale);
} image_t;

typedef struct event{
    sfEventType type;
    void (*action)(sys_t *sys, sfEvent event, image_t *target);
} event_t;

typedef struct text{
    sfText *Text;
    sfVector2f Position;
    sfFont *Font;
    char String[1024];
    void (*update)(struct text *txt, sfRenderWindow *window, char *str, unsigned int size);
} text_t;

//update functions
void update_img(image_t *img, sfRenderWindow *window, float scale);
void update_txt(text_t *txt, sfRenderWindow *window, const char *str, unsigned int size);
//create functions
image_t *image_create(int x, int y, char *img);
event_t *event_list_create(int size);
text_t *text_create(int x, int y, char *font);
//event functions
void exit_window(sys_t *sys, sfEvent event);
void check_mouseclick_menu(sys_t *sys, sfEvent event, image_t *target);
//destroy functions
void destroy_img(image_t *img);