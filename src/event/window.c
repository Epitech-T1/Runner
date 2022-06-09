/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** window
*/

#include "../../include/runner.h"

void window_components(game_t *game)
{
    load_font(game);
    bg_window();
    menu_texts(game);
    players_texts(game);
}

void window_close(game_t *game)
{
    sfMusic_destroy(game->music);
    sfRenderWindow_close(game->next->window);
}
