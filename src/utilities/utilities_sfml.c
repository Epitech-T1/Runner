/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** utilities_sfml
*/

#include "../../include/runner.h"

sfVector2f position(int x, int y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

int pressed_or_not(sfSprite *sprite, sfVector2f pos, const int size)
{
    sfVector2f pos_sprite = sfSprite_getPosition(sprite);

    if (pos.x >= pos_sprite.x && pos.x <= pos_sprite.x + size &&
        pos.y >= pos_sprite.y && pos.y <= pos_sprite.y + size)
        return (1);
    return (0);
}

parallax_t *init_parallax(char *filepath, sfVector2f my_pos, sfIntRect rect)
{
    parallax_t *parallax = malloc(sizeof(parallax_t));

    if (parallax == NULL)
        return (NULL);
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    if (texture == NULL)
        return (NULL);
    parallax->texture = texture;
    sfSprite *sprite = sfSprite_create();
    if (sprite == NULL)
        return (NULL);
    parallax->sprite = sprite;
    sfSprite_setTexture(parallax->sprite, parallax->texture, sfTrue);
    parallax->vector = my_pos;
    sfSprite_setPosition(parallax->sprite, parallax->vector);
    parallax->rect = rect;
    sfSprite_setTextureRect(parallax->sprite, parallax->rect);
    return (parallax);
}

object_t *obj(char *filepath, sfIntRect rect)
{
    object_t *object = malloc(sizeof(object_t));

    if (object == NULL)
        return (NULL);
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    if (texture == NULL)
        return ( NULL);
    object->texture = texture;
    sfSprite *sprite = sfSprite_create();
    if (sprite == NULL)
        return (NULL);
    object->sprite = sprite;
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    object->rect = rect;
    sfSprite_setTextureRect(object->sprite, object->rect);
    return (object);
}

player_t *anm(char *filepath, sfVector2f pos, sfVector2f sc, sfIntRect rect)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        return (NULL);
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    if (texture == NULL)
        return ( NULL);
    player->texture = texture;
    sfSprite *sprite = sfSprite_create();
    if (sprite == NULL)
        return (NULL);
    player->sprite = sprite;
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    player->vector = pos;
    sfSprite_setPosition(player->sprite, player->vector);
    player->rect = rect;
    sfSprite_setTextureRect(player->sprite, player->rect);
    player->scale = sc;
    sfSprite_setScale(player->sprite, player->scale);
    return (player);
}
