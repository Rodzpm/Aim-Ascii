/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <SFML/Graphics.h>
#include "app.h"
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>

void test_events(event_t *event_list, sfEvent event, sys_t *sys, image_t *target)
{
    for (int i = 0; event_list[i].type != -1; i++) {
        if (event_list[i].type == event.type)
            event_list[i].action(sys, event, target);
    }
}

sys_t *init(int width, int height)
{
    sys_t *system = malloc(sizeof(sys_t));
    int w = width; int h = height;
    sfVideoMode mode = {w, h, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "AIM ASCII",
    sfClose, NULL);
    sfVector2i wpos = {550, 200};
    sfWindow_setPosition(window, wpos);
    system->window = window;
    system->in_menu = true;
    system->score = 0;
    system->sec = 0;
    system->in_end = false;
    return system;
}

void menu(sys_t *sys, text_t *text, text_t *text2, text_t *text3, image_t *play, image_t *quit)
{
    if (sys->in_menu && !sys->in_end){
        text->update(text, sys->window, "Aim Ascii", 80);
        text2->update(text2, sys->window, "Le Jeu", 40);
        text3->update(text3, sys->window, "Fait par un gros bg", 20);
        play->update(play, sys->window, 1.0);
        quit->update(quit, sys->window, 1.0);
    }
}

void game(sys_t *sys, image_t *target, text_t *score, text_t *score_txt, text_t *tps, text_t *tps_txt)
{
    if (!sys->in_menu && !sys->in_end){
        target->update(target, sys->window, 0.25);
        score_txt->update(score_txt, sys->window, "Score : ", 40);
        int i = sys->score;
        char s[100];
        sprintf(s, "%d", i);
        score->update(score, sys->window, s, 40);
        tps_txt->update(tps_txt, sys->window, "Time : ", 40);
        int j = sys->sec;
        char t[100];
        sprintf(t, "%d", j);
        tps->update(tps, sys->window, t, 40);
        if (sys->sec == 30)
            sys->in_end = true;
    }
}

void end(sys_t *sys, text_t *total, text_t *total_txt)
{
    if(!sys->in_menu && sys->in_end){
        total_txt->update(total_txt, sys->window, "Score Total", 60);
        int i = sys->score;
        char s[100];
        sprintf(s, "%d", i);
        total->update(total, sys->window, s, 60);        
    }
}

int main(void)
{
    sys_t *sys = init(800,600);
    sfEvent event;
    event_t *event_list = event_list_create(5);
    int temps = 0;
    srand(time(NULL));
    
    //menu
    text_t *aim_ascii = text_create(290,50, "src/BebasNeue-Regular.ttf");
    text_t *sous_titre = text_create(360,140, "src/BebasNeue-Regular.ttf");
    text_t *bas = text_create(330,570, "src/BebasNeue-Regular.ttf");
    
    image_t *play_button = image_create(250, 220, "src/play-button.png");
    image_t *quit_button = image_create(250, 350, "src/quit-button.png");

    //game
    int targ_x = rand() % 750;
    int targ_y = 150 + rand() % 400;
    image_t *target = image_create(targ_x, targ_y, "src/target.png");

    text_t *score = text_create(150, 20, "src/BebasNeue-Regular.ttf");
    text_t *score_txt = text_create(50, 20, "src/BebasNeue-Regular.ttf");
    text_t *tps = text_create(750, 20, "src/BebasNeue-Regular.ttf");
    text_t *tps_txt = text_create(650, 20, "src/BebasNeue-Regular.ttf");

    text_t *total = text_create(380, 300, "src/BebasNeue-Regular.ttf");
    text_t *total_txt = text_create(280, 200, "src/BebasNeue-Regular.ttf");

    while (sfRenderWindow_isOpen(sys->window)) {
        if(temps == 18000){
            sys->sec += 1;
            temps = 0;
        }
        while (sfRenderWindow_pollEvent(sys->window, &event))
            test_events(event_list, event, sys, target);
        sfRenderWindow_clear(sys->window, sfWhite);
        menu(sys, aim_ascii, sous_titre, bas, play_button, quit_button);
        game(sys, target, score, score_txt, tps, tps_txt);
        end(sys, total, total_txt);
        sfRenderWindow_display(sys->window);
        if (!sys->in_menu)
            temps++;
    }
    destroy_img(play_button);
    destroy_img(quit_button);
    destroy_img(target);
    sfRenderWindow_destroy(sys->window);
}
