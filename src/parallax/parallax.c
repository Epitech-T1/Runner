/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** parallax
*/

#include "../../include/runner.h"

char **init_png(void)
{
    char **png = malloc(sizeof(char *) * 10);

    png[0] = "sprite/CaveTheme/bg/00.png";
    png[1] = "sprite/CaveTheme/bg/1.png";
    png[2] = "sprite/CaveTheme/bg/2.png";
    png[3] = "sprite/CaveTheme/bg/3.png";
    png[4] = "sprite/CaveTheme/bg/4.png";
    png[5] = "sprite/CaveTheme/bg/5.png";
    png[6] = "sprite/CaveTheme/bg/6.png";
    png[7] = "sprite/CaveTheme/bg/7.png";
    png[8] = "sprite/CaveTheme/bg/8.png";
    png[9] = "sprite/CaveTheme/bg/BlueLight.png";
    return (png);
}

parallax_t **set_png(int x, int y)
{
    parallax_t **bg = malloc(sizeof(parallax_t) * 16);
    char **pn = init_png();

    bg[0] = init_parallax(pn[0], (sfVector2f){0, 0}, (sfIntRect){0, 0, x, y});
    bg[1] = init_parallax(pn[1], (sfVector2f){0, 0}, (sfIntRect){0, 0, x, y});
    bg[2] = init_parallax(pn[1], (sfVector2f){x, 0}, (sfIntRect){0, 0, x, y});
    bg[3] = init_parallax(pn[2], (sfVector2f){0, 0}, (sfIntRect){0, 0, x, y});
    bg[4] = init_parallax(pn[2], (sfVector2f){x, 0}, (sfIntRect){0, 0, x, y});
    bg[5] = init_parallax(pn[3], (sfVector2f){0, 0}, (sfIntRect){0, 0, x, y});
    bg[6] = init_parallax(pn[3], (sfVector2f){x, 0}, (sfIntRect){0, 0, x, y});
    bg[7] = init_parallax(pn[4], (sfVector2f){0, 0}, (sfIntRect){0, 0, x, y});
    bg[8] = init_parallax(pn[4], (sfVector2f){x, 0}, (sfIntRect){0, 0, x, y});
    bg[9] = init_parallax(pn[5], (sfVector2f){0, 0}, (sfIntRect){0, 0, x, y});
    bg[10] = init_parallax(pn[5], (sfVector2f){x, 0}, (sfIntRect){0, 0, x, y});
    bg[11] = init_parallax(pn[6], (sfVector2f){0, 0}, (sfIntRect){0, 0, x, y});
    bg[12] = init_parallax(pn[7], (sfVector2f){0, 0}, (sfIntRect){0, 0, x, y});
    bg[13] = init_parallax(pn[7], (sfVector2f){x, 0}, (sfIntRect){0, 0, x, y});
    bg[14] = init_parallax(pn[8], (sfVector2f){0, 0}, (sfIntRect){0, 0, x, y});
    bg[15] = init_parallax(pn[9], (sfVector2f){0, 0}, (sfIntRect){0, 0, x, y});
    return (bg);
}

void move(sfSprite *sprite, sfVector2f pos_init, int value)
{
    if (sfSprite_getPosition(sprite).x < value + 1)
        sfSprite_setPosition(sprite, (sfVector2f){1280 + pos_init.x, 0});
    sfSprite_move(sprite, pos_init);
}

void move_parallax(parallax_t **bg)
{
    move(bg[1]->sprite, (sfVector2f){-100/100}, -1280);
    move(bg[2]->sprite, (sfVector2f){-100/100}, -1280);
    move(bg[3]->sprite, (sfVector2f){-150/100}, -1280);
    move(bg[4]->sprite, (sfVector2f){-150/100}, -1280);
    move(bg[5]->sprite, (sfVector2f){-200/100}, -1280);
    move(bg[6]->sprite, (sfVector2f){-200/100}, -1280);
    move(bg[7]->sprite, (sfVector2f){-250/100}, -1280);
    move(bg[8]->sprite, (sfVector2f){-250/100}, -1280);
    move(bg[9]->sprite, (sfVector2f){-300/100}, -1280);
    move(bg[10]->sprite, (sfVector2f){-300/100}, -1280);
    move(bg[12]->sprite, (sfVector2f){-500/100}, -1280);
    move(bg[13]->sprite, (sfVector2f){-500/100}, -1280);
}

void parallax(game_t *game)
{
    if (game->seconds > 0.01)
        move_parallax(game->parallax);
    for (unsigned int i = 0; i != 16; i++) {
        sfRenderWindow_drawSprite(game->next->window,
            game->parallax[i]->sprite, NULL);
        sfSprite_setTextureRect(game->parallax[i]->sprite,
            game->parallax[i]->rect);
    }
}
