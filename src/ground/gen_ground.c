/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** gen_ground
*/

#include "../../include/runner.h"

void set_position_init(game_t *game, int *next_ground_pos_y)
{
    if (game->c - 1 >= 0 && game->c -1 <= 2)
        *next_ground_pos_y += 128 -
            game->object[(game->c - 48) - 1]->rect.height - 8;
    else
        *next_ground_pos_y += 148 -
            game->object[(game->c - 48) - 1]->rect.height - 8;
}

map_t *create_map(game_t *game, int x, int y, int reset)
{
    map_t *map = malloc(sizeof(map_t));
    static int next_ground_pos = 0;
    int next_ground_pos_y = y;

    map->map = sfSprite_create();
    if (map == NULL || map->map == NULL)
        return (NULL);
    next_ground_pos += game->object[(game->c - 48) - 1]->rect.width;
    set_position_init(game, &next_ground_pos_y);
    if (reset == 1)
        next_ground_pos = 128;
    if (x > 0)
        next_ground_pos += x;
    sfSprite_setTexture(map->map,
        game->object[(game->c - 48) - 1]->texture, sfTrue);
    sfSprite_setPosition(map->map,
        (sfVector2f){next_ground_pos, next_ground_pos_y});
    sfSprite_setTextureRect(map->map, game->object[(game->c - 48) - 1]->rect);
    return (map);
}

int next_list_ground(char *buffer, int *pos1, int pos2, int *stage)
{
    int add;
    int space_add = 0;

    for (add = 0; buffer[pos2] == '0'; pos2++) {
        if (buffer[pos2 + 1] == '\n') {
            add++;
            *stage = 1;
        }
        add++;
        space_add += 100;
    }
    *pos1 += add;
    return (space_add);
}

int set_pos_y(char *str)
{
    int i = 0;
    int res = 0;
    int beging = 580;

    while (str[i++] != '\0')
        if (str[i] == '\n')
            res++;
    if (res == 1)
        beging = 454;
    if (res == 2)
        beging = 308;
    return (beging);
}