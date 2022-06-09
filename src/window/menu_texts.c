/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** menu_texts
*/

#include "../../include/runner.h"

void load_font( game_t *game)
{
    game->font = sfFont_createFromFile(FONT);
    if (game->font == NULL)
        return;
}

sfText *get_text(sfVector2f pos, char *sentence, int size, sfFont *font)
{
    sfText *text = sfText_create();
    if (text == NULL)
        return (NULL);
    sfText_setPosition(text, pos);
    sfText_setString(text, sentence);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, size);
    return (text);
}

void menu_texts(game_t *game)
{
    game->texts->title = get_text((sfVector2f){380, 160},
        "Demonica", 110, game->font);
    game->texts->players = get_text((sfVector2f){90, 25},
        "Skin", 40, game->font);
    game->texts->highest_score = get_text((sfVector2f){910, 25},
        "Highest score", 40, game->font);
    game->texts->new_highest = get_text((sfVector2f){400, 370},
        "New highest score", 60, game->font);
    game->texts->score = get_text((sfVector2f){1200, 25},
        "0", 40, game->font);
    game->texts->sound = get_text((sfVector2f){20, 600},
        "Sound", 40, game->font);
    game->texts->game_over = get_text((sfVector2f){320, 220},
        "Game over\n Try again", 130, game->font);
    game->texts->score_play = get_text((sfVector2f){1080, 25},
        "score", 40, game->font);
    game->texts->victory = get_text((sfVector2f){440, 220},
        "Victory", 130, game->font);
}

void draw_texts_start(game_t *game)
{
    sfRenderWindow_drawText(game->next->window, game->texts->title, NULL);
    sfRenderWindow_drawText(game->next->window, game->texts->players, NULL);
    sfRenderWindow_drawText(game->next->window, game->texts->highest_score,
        NULL);
    sfRenderWindow_drawText(game->next->window, game->texts->score, NULL);
    sfRenderWindow_drawText(game->next->window, game->texts->sound, NULL);
}

void draw_texts_end(game_t *game)
{
    sfRenderWindow_drawText(game->next->window, game->texts->game_over, NULL);
    sfRenderWindow_drawText(game->next->window, game->texts->score_play, NULL);
    sfRenderWindow_drawText(game->next->window, game->texts->score, NULL);
}
