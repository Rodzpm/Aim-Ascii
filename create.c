/*
** EPITECH PROJECT, 2022
** create
** File description:
** create programm
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "app.h"

image_t *image_create(int x, int y, char *img)
{
    image_t *render = malloc(sizeof(image_t));
    sfVector2f pos = {x, y};
    render->pos = pos;
    render->sprite = sfSprite_create();
    render->texture = sfTexture_createFromFile(img, NULL);
    render->update = &update_img;
    return render;
}

text_t *text_create(int x, int y, char *font)
{
    text_t *render = malloc(sizeof(text_t));
    sfVector2f pos = {x, y};
    render->Position = pos;
    render->Text = sfText_create();
    render->Font = sfFont_createFromFile(font);
    render->update = &update_txt;
    return render;
}

event_t *event_list_create(int size)
{
    event_t *list = malloc(sizeof(event_t) * (size + 1));
    list[0] = (event_t){sfEvtClosed, &exit_window};
    list[1] = (event_t){sfEvtMouseButtonPressed, &check_mouseclick_menu};
    list[size] = (event_t){-1, NULL};
    return list;
}
