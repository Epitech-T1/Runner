/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** ground
*/

#include "../../include/runner.h"

char **init_ground(void)
{
    char **ground = malloc(sizeof(char *) * 1);

    ground[0] = "sprite/CaveTheme/objet/ground.png";
    return (ground);
}

object_t **set_object(void)
{
    object_t **ob = malloc(sizeof(object_t) * 9);
    char **gd = init_ground();

    ob[0] = obj(gd[0], (sfIntRect){0, 15, 128, 110});
    ob[1] = obj(gd[0], (sfIntRect){193, 15, 127, 110});
    ob[2] = obj(gd[0], (sfIntRect){384, 15, 127, 110});
    ob[3] = obj(gd[0], (sfIntRect){76, 160, 61, 126});
    ob[4] = obj(gd[0], (sfIntRect){193, 160, 126, 126});
    ob[5] = obj(gd[0], (sfIntRect){384, 160, 71, 126});
    ob[6] = obj(gd[0], (sfIntRect){69, 320, 59, 126});
    ob[7] = obj(gd[0], (sfIntRect){193, 320, 126, 126});
    ob[8] = obj(gd[0], (sfIntRect){384, 320, 59, 126});
    return (ob);
}

void mv_gd(sfSprite *sprite, sfVector2f speed)
{
    sfSprite_move(sprite, speed);
}

void move_ground(game_t *game)
{
    for (int i = 0; game->map[i] != NULL; i++)
        mv_gd(game->map[i]->map, (sfVector2f){-400/100});
}

void ground(game_t *game)
{
    if (game->seconds > 0.03)
        move_ground(game);
    for (int i = 0; game->map[i] != NULL; i++)
        sfRenderWindow_drawSprite(game->next->window, game->map[i]->map, NULL);
}