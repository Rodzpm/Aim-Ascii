/*
** EPITECH PROJECT, 2022
** destroy
** File description:
** destroy
*/

#include <SFML/Graphics.h>
#include "app.h"

void destroy_img(image_t *img)
{
    sfSprite_destroy(img->sprite);
    sfTexture_destroy(img->texture);
}
