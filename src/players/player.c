/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** player
*/

#include "../../include/runner.h"

char **init_player(void)
{
    char **player = malloc(sizeof(char *) * 7);

    player[0] = "sprite/players/p1r.png";
    player[1] = "sprite/players/p1j.png";
    player[2] = "sprite/players/p2r.png";
    player[3] = "sprite/players/p2j.png";
    player[4] = "sprite/players/p3r.png";
    player[5] = "sprite/players/p3j.png";
    return (player);
}

int jump_players(game_t *game, float velocity)
{
    static int pos_init = 460;
    static int status = 0;

    if (status == 0) {
        pos_init -= velocity;
        if (pos_init <= 280)
            status = 1;
    }
    if (status == 1) {
        pos_init += velocity;
        if (pos_init >= 460) {
            status = 0;
            return (0);
        }
    }
    sfSprite_setPosition(game->players[(game->next->player + 1)]->sprite,
        position(200, pos_init));
    sfSprite_setTextureRect(game->players[(game->next->player + 1)]->sprite,
        game->players[(game->next->player + 1)]->rect);
    sfRenderWindow_drawSprite(game->next->window,
        game->players[(game->next->player + 1)]->sprite, NULL);
}

player_t **set_player(void)
{
    player_t **pl1 = malloc(sizeof(player_t) * 6);
    char **pl = init_player();

    pl1[0] = anm(pl[0], (sfVector2f){200, 460}, (sfVector2f){1.7, 1.7},
        (sfIntRect){0, 0, 66, 110});
    pl1[1] = anm(pl[1], (sfVector2f){200, 460}, (sfVector2f){1.7, 1.7},
        (sfIntRect){0, 0, 54, 134});
    pl1[2] = anm(pl[2], (sfVector2f){200, 460}, (sfVector2f){1.7, 1.7},
        (sfIntRect){0, 0, 76, 103});
    pl1[3] = anm(pl[3], (sfVector2f){200, 460}, (sfVector2f){1.7, 1.7},
        (sfIntRect){0, 0, 73, 149});
    pl1[4] = anm(pl[4], (sfVector2f){200, 460}, (sfVector2f){1.7, 1.7},
        (sfIntRect){0, 0, 79, 94});
    pl1[5] = anm(pl[5], (sfVector2f){200, 460}, (sfVector2f){1.7, 1.7},
        (sfIntRect){0, 0, 66, 155});
    return (pl1);
}

void display_players(game_t *game)
{
    if (game->players[game->next->player]->actions == 1)
        game->players[game->next->player]->actions = jump_players(game, 7);
    else {
        game_over(game);
        sfSprite_setTextureRect(game->players[game->next->player]->sprite,
            game->players[game->next->player]->rect);
        sfRenderWindow_drawSprite(game->next->window,
            game->players[game->next->player]->sprite, NULL);
    }
    game->score_game = int_to_char(game->score);
    sfText_setString(game->texts->score, game->score_game);
    sfRenderWindow_drawText(game->next->window, game->texts->score_play, NULL);
    sfRenderWindow_drawText(game->next->window, game->texts->score, NULL);
    sfRenderWindow_drawSprite(game->next->window, game->wnd[4]->button, NULL);
    free(game->score_game);
}
