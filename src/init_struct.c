/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** init_struct
*/

#include "../include/runner.h"

option_t *init_option(void)
{
    option_t *option = malloc(sizeof(option_t));

    if (option == NULL)
        return (NULL);
    option->sound = 1;
    return (option);
}

game_next_t *init_game_next(void)
{
    const int x = 1280;
    const int y = 720;
    sfVideoMode video_mode = {x, y, 32};
    game_next_t *next = malloc(sizeof(game_next_t));

    next->window = sfRenderWindow_create(video_mode, "my_runner",
        sfResize | sfClose, NULL);
    if (next->window == NULL)
        return (NULL);
    next->highest = 0;
    next->won = 0;
    next->player = 0;
    next->option = init_option();
    next->pos = 0;
    return (next);
}

game_t *init_game(char *argv)
{
    game_t *game = malloc(sizeof(game_t));
    int x = 1280;
    int y = 720;

    game->texts = malloc(sizeof(texts_t));
    if (game == NULL || game->texts == NULL)
        return (NULL);
    game->parallax = set_png(x, y);
    game->object = set_object();
    game->wnd = resource_menu();
    game->map = malloc(sizeof(map_t *) * 104);
    game->bg = bg_window();
    game->pls = ress_pl();
    game->clock = sfClock_create();
    game->score = 0;
    game->mode = 0;
    game->next = init_game_next();
    game->players = set_player();
    game->players[game->next->player]->actions = 0;
    generator(argv, game);
    return (game);
}
