/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** players_texts
*/

#include "../../include/runner.h"

void players_texts(game_t *game)
{
    game->texts->ch_pl = get_text((sfVector2f){270, 50},
        "Choose your player", 80, game->font);
    game->texts->player1 = get_text((sfVector2f){185, 500},
        "Nana Osaki", 40, game->font);
    game->texts->player2 = get_text((sfVector2f){510, 500},
        "Ino Yamanaka", 40, game->font);
    game->texts->player3 = get_text((sfVector2f){870, 500},
        "Asuna Yuuki", 40, game->font);
}

void draw_player_texts(game_t *game)
{
    sfRenderWindow_drawText(game->next->window, game->texts->ch_pl, NULL);
    sfRenderWindow_drawText(game->next->window, game->texts->player1, NULL);
    sfRenderWindow_drawText(game->next->window, game->texts->player2, NULL);
    sfRenderWindow_drawText(game->next->window, game->texts->player3, NULL);
}
