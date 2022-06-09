/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** menu_display
*/


#include "../../include/runner.h"

void draw_start(game_t *game)
{
    display_menu(game);
    draw_texts_start(game);
}

void draw_game(game_t *game, char *argv)
{
    parallax(game);
    ground(game);
    display_players(game);
}

void draw_mnu_players(game_t *game)
{
    display_menu_players(game);
    draw_player_texts(game);
}

void draw_end(game_t *game)
{
    draw_texts_end(game);
}

void draw_victory(game_t *game)
{
    draw_text_victory(game);
}
