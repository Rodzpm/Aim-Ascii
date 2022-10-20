/*
** EPITECH PROJECT, 2022
** update
** File description:
** update file
*/

#include <SFML/Graphics.h>
#include "app.h"

void update_img(image_t *img, sfRenderWindow *window, float scale)
{
    sfVector2f sc = {scale, scale};
    sfSprite_setScale(img->sprite, sc);
    sfSprite_setTexture(img->sprite, img->texture, sfFalse);
    sfSprite_setPosition(img->sprite, img->pos);
    sfRenderWindow_drawSprite(window, img->sprite, NULL);
}

void update_txt(text_t *txt, sfRenderWindow *window, 
const char *str, unsigned int size)
{
        sfText_setPosition(txt->Text, txt->Position);
        sfText_setString(txt->Text, str);
        sfText_setColor(txt->Text, sfBlack);
        sfText_setFont(txt->Text, txt->Font);
        sfText_setCharacterSize(txt->Text, size);
        sfRenderWindow_drawText(window, txt->Text, NULL);
}