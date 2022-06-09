/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** select_mode
*/

#include "../include/runner.h"

int select_mode_2(game_t *game, char *str)
{
    if (strcmp(str, "-h") == 0)
        help();
    if (strcmp(str, "-i") == 0)
        select_mode(game, str);
    return (0);
}

void select_mode_next(game_t *game)
{
    if (game->mode == 3)
        draw_mnu_players(game);
    if (game->mode == 4)
        draw_victory(game);
}

void select_mode(game_t *game, char *av)
{
    if (game->mode == 0)
        draw_start(game);
    if (game->mode == 1)
        draw_game(game, av);
    if (game->mode == 2)
        draw_end(game);
    select_mode_next(game);
}
