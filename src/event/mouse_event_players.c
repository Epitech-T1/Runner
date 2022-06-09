/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** mouse_event_players
*/

#include "../../include/runner.h"

void mouse_event_pl(game_t *game)
{
    sfVector2f mouse = position(game->next->event.mouseButton.x,
        game->next->event.mouseButton.y);
    int size = 256;

    if (pressed_or_not(game->pls[0]->ch_pls, mouse, size) ==  1)
        game->mode = 1;
    if (pressed_or_not(game->pls[1]->ch_pls, mouse, size) ==  1) {
        game->next->player = 2;
        game->mode = 1;
    }
    if (pressed_or_not(game->pls[2]->ch_pls, mouse, size) ==  1) {
        game->next->player = 4;
        game->mode = 1;
    }
}

void mouse_back(game_t *game)
{
    sfVector2f mouse = position(game->next->event.mouseButton.x,
        game->next->event.mouseButton.y);
    int size = 80;

    if (pressed_or_not(game->wnd[4]->button, mouse, size) == 1)
        game->mode = 0;
}
