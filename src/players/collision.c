/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** collision
*/

#include "../../include/runner.h"

int object_collision(game_t *game)
{
    sfVector2f pos;
    sfVector2f possol;

    pos = sfSprite_getPosition(game->players[game->next->player]->sprite);
    for (int i = 0; game->map[i] != NULL; i++) {
        possol = sfSprite_getPosition(game->map[i]->map);
        if ((abs((pos.x + 33 >= possol.x -10) &&
            (pos.x + 33 <= possol.x + 120))))
            return (0);
    }
    return (1);
}

void game_over(game_t *game)
{
    if (game->players[game->next->player]->actions == 0 &&
        object_collision(game) == 1) {
        stop_music(game);
        if (game->score > game->next->highest)
            game->next->highest = game->score;
        sfText_setString(game->texts->score, int_to_char(game->next->highest));
        game->mode = 2;
    }
}

void victory(game_t *game)
{
    for (int i = 0; game->map[i] != NULL; i++) {
        if (game->map[i] == NULL && object_collision(game) == 1)
            stop_music(game);
            game->mode = 4;
    }
}
