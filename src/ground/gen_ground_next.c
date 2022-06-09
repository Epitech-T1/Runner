/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** gen_ground_next
*/

#include "../../include/runner.h"

int list_gen_next(game_t *game, int x, int *y)
{
    game->c = game->buffer[x];
    if (game->buffer[x + 1] == '\n') {
        game->reset = 1;
        *y += 126;
    }
    game->map[game->next->pos] = create_map(game, 0, *y, game->reset);
}

int list_ground_next(game_t *game, int x, int *y)
{
    static int space = 0;
    static int stage = 0;

    if (game->buffer[x] == '0') {
        space = next_list_ground(game->buffer, &x, x, &stage);
        if (stage == 1) {
            *y += 126;
            space = 0;
            stage = 0;
            game->reset = 1;
        }
        game->c = game->buffer[x];
        game->map[game->next->pos] = create_map(game, space, *y, game->reset);
    } else {
        list_gen_next(game, x, y);
    }
    game->next->pos++;
    return (x);
}

void list_ground(game_t *game)
{
    unsigned int x;
    int y = set_pos_y(game->buffer);
    game->reset = 0;

    for (x = 0; game->buffer[x] != '\0'; x++) {
        if (game->buffer[x] != '\n')
            x = list_ground_next(game, x, &y);
        game->reset = 0;
    }
    game->map[game->next->pos] = NULL;
}

int generator(char *filename, game_t *game)
{
    int fd;
    int sizemax_map = 200;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (84);
    game->buffer = malloc(sizeof(char) * (sizemax_map + 1));
    if (game->buffer == NULL)
        return (84);
    for (int i = 0; i < sizemax_map; i++)
        game->buffer[i] = 0;
    read(fd, game->buffer, sizemax_map);
    list_ground(game);
    close(fd);
    return (0);
}
