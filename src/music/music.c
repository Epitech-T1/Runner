/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** music
*/

#include "../../include/runner.h"

void play_music(game_t *game)
{
    char *filepath = "sprite/limbo.ogg";

    if (game->next->option->sound == 1) {
        game->music = sfMusic_createFromFile(filepath);
        sfMusic_play(game->music);
    }
}

void mute_music(game_t *game)
{
    if (game->next->option->sound == 1) {
        game->next->option->sound == 0;
        pause_music(game);
    }
}

void pause_music(game_t *game)
{
    if (game->music == NULL || game->next->option->sound == 0)
        return;
    sfMusic_pause(game->music);
}

void stop_music(game_t *game)
{
    if (game->music == NULL)
        return;
    if (game->next->option->sound == 1)
        sfMusic_stop(game->music);
}
