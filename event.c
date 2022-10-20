/*
** EPITECH PROJECT, 2022
** event
** File description:
** event
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include "app.h"
#include <stdio.h>

void exit_window(sys_t *sys, sfEvent event)
{
    sfRenderWindow_close(sys->window);
}

void check_mouseclick_menu(sys_t *sys, sfEvent event, image_t *target)
{
    int posx = event.mouseButton.x;
    int posy = event.mouseButton.y;
    if (sys->in_menu){
        if (posx >= 250 && posx <= 550 && posy >= 220 && posy <= 340)
            sys->in_menu = false;

        if (posx >= 250 && posx <= 550 && posy >= 350 && posy <= 470)
            sfRenderWindow_close(sys->window);
    }
    else{
        if (posx >= target->pos.x && posx <= target->pos.x + 50
        && posy >= target->pos.y && posy <= target->pos.y + 50){
            sys->score += 1;
            target->pos.x = rand() % 750;
            target->pos.y = 150 + rand() % 400;
        }
    }
}

void check_mouseclick_game(sfRenderWindow *window, sfEvent event)
{
    int posx = event.mouseButton.x;
    int posy = event.mouseButton.y;
}