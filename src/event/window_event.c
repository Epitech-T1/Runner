/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** keyboard
*/

#include "../../include/runner.h"

void keyboard_event(game_t *game)
{
    sfVector2f pos2 = {0, -100};
    float velocity = 7;

    if (sfKeyboard_isKeyPressed(sfKeySpace))
        game->players[game->next->player]->actions = 1;
}

void mouse_event_start_next(game_t *game, sfVector2f mouse)
{
    int size2 = 80;

    if (pressed_or_not(game->wnd[1]->button, mouse, size2) == 1)
        play_music(game);
    if (pressed_or_not(game->wnd[2]->button, mouse, size2) == 1)
        mute_music(game);
}

void mouse_event_start(game_t *game)
{
    sfVector2f mouse = position(game->next->event.mouseButton.x,
        game->next->event.mouseButton.y);
    int size = 256;

    if (pressed_or_not(game->wnd[0]->button, mouse, size) == 1) {
        game->mode = 3;
    }
    if (pressed_or_not(game->wnd[3]->button, mouse, size) == 1) {
        game->score = 0;
        game->mode = 1;
    }
    mouse_event_start_next(game, mouse);
}

void mouse_event(game_t *game)
{
    if (game->mode == 0)
        mouse_event_start(game);
    if (game->mode == 1 || game->mode == 2)
        mouse_back(game);
    if (game->mode == 3)
        mouse_event_pl(game);
}

void window_event(game_t *game)
{
    if (game->next->event.type == sfEvtClosed)
        window_close(game);
    if (game->next->event.type == sfEvtKeyPressed)
        keyboard_event(game);
    if (game->next->event.type == sfEvtMouseButtonPressed)
        mouse_event(game);
}
