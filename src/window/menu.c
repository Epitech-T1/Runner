/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** menu
*/

#include "../../include/runner.h"

bg_menu_t *bg_window(void)
{
    bg_menu_t *bg = malloc(sizeof(bg_menu_t) * 1);
    const int x = 1280;
    const int y = 720;

    sfTexture *texture = sfTexture_createFromFile("sprite/button/demonica.jpg",
        NULL);
    bg->texture_menu = texture;
    sfSprite *sprite = sfSprite_create();
    if (sprite == NULL || texture == NULL || bg == NULL)
        return (NULL);
    bg->bg_menu = sprite;
    sfIntRect rect = {0, 0, x, y};
    sfSprite_setTexture(bg->bg_menu, bg->texture_menu, sfTrue);
    bg->pos = position(0, 0);
    sfSprite_setPosition(bg->bg_menu, bg->pos);
    bg->rect = rect;
    sfSprite_setTextureRect(bg->bg_menu, bg->rect);
    return (bg);
}

window_t *window(char *filename, sfVector2f pos, sfVector2f scale)
{
    window_t *wnd = malloc(sizeof(window_t));

    if (wnd == NULL)
        return (NULL);
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    if (texture == NULL)
        return (NULL);
    wnd->texture = texture;
    sfSprite *sprite = sfSprite_create();
    if (sprite == NULL)
        return (NULL);
    wnd->button = sprite;
    sfSprite_setTexture(wnd->button, wnd->texture, sfTrue);
    wnd->vector = pos;
    sfSprite_setPosition(wnd->button, wnd->vector);
    wnd->scale = scale;
    sfSprite_setScale(wnd->button, wnd->scale);
    return (wnd);
}

char **init_menu(void)
{
    char **menu = malloc(sizeof(char *) * 6);

    menu[0] = "sprite/button/menu.png";
    menu[1] = "sprite/button/sound_on.png";
    menu[2] = "sprite/button/sound_off.png";
    menu[3] = "sprite/button/play.png";
    menu[4] = "sprite/button/back.png";
    return (menu);
}

window_t **resource_menu(void)
{
    window_t **wnd = malloc(sizeof(window_t) * 6);
    char **wn = init_menu();

    wnd[0] = window(wn[0], (sfVector2f){25, 25}, (sfVector2f){0.2, 0.2});
    wnd[1] = window(wn[1], (sfVector2f){20, 650}, (sfVector2f){0.06, 0.06});
    wnd[2] = window(wn[2], (sfVector2f){90, 650}, (sfVector2f){0.06, 0.06});
    wnd[3] = window(wn[3], (sfVector2f){450, 250}, (sfVector2f){0.2, 0.2});
    wnd[4] = window(wn[4], (sfVector2f){10, 5}, (sfVector2f){0.3, 0.3});
    return (wnd);
}

void display_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->next->window, game->bg->bg_menu, NULL);
    for (int i = 0; i != 4; i++)
        sfRenderWindow_drawSprite(game->next->window, game->wnd[i]->button,
            NULL);
}
