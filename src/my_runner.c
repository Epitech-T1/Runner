/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my_runner
*/

#include "../include/runner.h"

int my_runner(game_t *game, char *str)
{
    sfRenderWindow_setFramerateLimit(game->next->window, 60);
    window_components(game);
    play_music(game);
    while (sfRenderWindow_isOpen(game->next->window)) {
        game->time = sfClock_getElapsedTime(game->clock);
        game->seconds = game->time.microseconds / 1000000.0;
        while (sfRenderWindow_pollEvent(game->next->window,
            &game->next->event))
            window_event(game);
        clock(game);
        select_mode(game, str);
        sfRenderWindow_display(game->next->window);
        sfRenderWindow_clear(game->next->window, sfBlack);
    }
    return (0);
}

static int check(int argc, char **argv)
{
    game_t *game = init_game(av[1]);

    if (game == NULL)
        return (84);
    if (argv[1][0] == '-') {
        select_mode_2(game, argv[1]);
        return (0);
    }
    if (my_runner(game, argv[1]) == 84)
        return (84);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    check(ac, av);
    return (0);
}
