/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** clock
*/

#include "../include/runner.h"

void clock_next(game_t *game)
{
    if (game->players[2]->rect.left >= 456)
        game->players[2]->rect.left = 0;
    if (game->players[3]->rect.left >= 803)
        game->players[3]->rect.left = 0;
    if (game->players[4]->rect.left >= 474)
        game->players[4]->rect.left = 0;
    if (game->players[5]->rect.left >= 660)
        game->players[5]->rect.left = 0;
}

void clock(game_t *game)
{
    if (game->seconds >= 0.15) {
        game->score++;
        game->players[0]->rect.left += 66;
        game->players[1]->rect.left += 54;
        game->players[2]->rect.left += 76;
        game->players[3]->rect.left += 73;
        game->players[4]->rect.left += 79;
        game->players[5]->rect.left += 66;
        sfClock_restart(game->clock);
    }
    if (game->players[0]->rect.left >= 330)
        game->players[0]->rect.left = 0;
    if (game->players[1]->rect.left >= 540)
        game->players[1]->rect.left = 0;
    clock_next(game);
}
