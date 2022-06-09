/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** victory
*/

#include "../../include/runner.h"

void draw_text_victory(game_t *game)
{
    sfRenderWindow_drawText(game->next->window, game->texts->victory, NULL);
    sfRenderWindow_drawText(game->next->window, game->texts->score_play, NULL);
    sfRenderWindow_drawText(game->next->window, game->texts->score, NULL);
    if (game->next->option->increase == 0) {
        sfRenderWindow_drawText(game->next->window, game->texts->new_highest,
            NULL);
        sfText_setPosition(game->texts->score, position(480, 450));
        sfRenderWindow_drawText(game->next->window, game->texts->score, NULL);
    }
}
