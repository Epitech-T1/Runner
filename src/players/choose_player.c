/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** choose_player
*/

#include "../../include/runner.h"

ch_pl_t *pls(char *filename, sfVector2f pos, sfVector2f scale)
{
    ch_pl_t *pls = malloc(sizeof(ch_pl_t));

    if (pls == NULL)
        return (NULL);
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    if (texture == NULL)
        return (NULL);
    pls->texture = texture;
    sfSprite *sprite = sfSprite_create();
    if (sprite == NULL)
        return (NULL);
    pls->ch_pls = sprite;
    sfSprite_setTexture(pls->ch_pls, pls->texture, sfTrue);
    pls->vector = pos;
    sfSprite_setPosition(pls->ch_pls, pls->vector);
    pls->scale = scale;
    sfSprite_setScale(pls->ch_pls, pls->scale);
    return (pls);
}

char **initt_player(void)
{
    char **players = malloc(sizeof(char *) * 4);

    players[0] = "sprite/players/p1.png";
    players[1] = "sprite/players/p2.png";
    players[2] = "sprite/players/p3.png";
    return (players);
}

ch_pl_t **ress_pl(void)
{
    ch_pl_t **pl = malloc(sizeof(ch_pl_t) * 4);
    char **ply = initt_player();

    pl[0] = pls(ply[0], (sfVector2f){200, 250}, (sfVector2f){2.5, 2.5});
    pl[1] = pls(ply[1], (sfVector2f){550, 250}, (sfVector2f){2.5, 2.5});
    pl[2] = pls(ply[2], (sfVector2f){900, 250}, (sfVector2f){2.5, 2.5});
    return (pl);
}

void display_menu_players(game_t *game)
{
    for (int i = 0; i != 3; i++)
        sfRenderWindow_drawSprite(game->next->window, game->pls[i]->ch_pls,
            NULL);
}
