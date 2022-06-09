/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** runner
*/

#ifndef RUNNER_H_
#define RUNNER_H_

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <dirent.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Window/Export.h>


#define GROUND1 "sprite/CaveTheme/objet/ground.png"
#define GROUND2 "sprite/CaveTheme/objet/gd_long.png"
#define GROUND3 "sprite/CaveTheme/objet/props.png"
#define FONT "sprite/fonts/font.ttf"
#define SOUND "sprite/button/sound.png"
#define SOUND_OFF "sprite/button/sound_off.png"
#define MENU "sprite/button/menu.png"
#define SCORE "sprite/button/score.png"
#define PLAY "sprite/button/play.png"

typedef struct parallax {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f vector;
} parallax_t;

typedef struct object {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f vector;
} object_t;

typedef struct map {
    sfSprite *map;
} map_t;

typedef struct window {
    sfSprite *button;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f vector;
} window_t;

typedef struct texts {
    sfText *title;
    sfText *players;
    sfText *highest_score;
    sfText *new_highest;
    sfText *score;
    sfText *sound;
    sfText *game_over;
    sfText *score_play;
    sfText *player1;
    sfText *player2;
    sfText *player3;
    sfText *ch_pl;
    sfText *victory;
} texts_t;

typedef struct option {
    int sound;
    int increase;
} option_t;

typedef struct game_next {
    sfRenderWindow *window;
    sfEvent event;
    option_t *option;
    int highest;
    int won;
    int player;
    int pos;
} game_next_t;

typedef struct bg_menu {
    sfSprite *bg_menu;
    sfTexture *texture_menu;
    sfVector2f pos;
    sfIntRect rect;
} bg_menu_t;

typedef struct choose_pl {
    sfSprite *ch_pls;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f vector;
} ch_pl_t;

typedef struct player {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f vector;
    sfIntRect rect;
    int actions;
} player_t;

typedef struct game {
    parallax_t **parallax;
    object_t **object;
    texts_t *texts;
    window_t **wnd;
    map_t **map;
    ch_pl_t **pls;
    player_t **players;
    game_next_t *next;
    sfFont *font;
    sfClock *clock;
    sfTime time;
    sfMusic *music;
    bg_menu_t *bg;
    int mode;
    int score;
    float seconds;
    char *buffer;
    char *score_game;
    char c;
    int reset;
} game_t;

// src/event/mouse_event_players.c
void mouse_event_pl(game_t *game);
void mouse_back(game_t *game);

// src/event/window_event.c
void keyboard_event(game_t *game);
void mouse_event(game_t *game);
void window_event(game_t *game);

// src/event/window.c
void window_components(game_t *game);
void window_close(game_t *game);

// src/ground/gen_ground_next.c
int list_gen_next(game_t *game, int x, int *y);
int list_ground_next(game_t *game, int x, int *y);
void list_ground(game_t *game);
int generator(char *filename, game_t *game);

// src/ground/gen_ground.c
void set_position_init(game_t *game, int *next_ground_pos_y);
map_t *create_map(game_t *game, int x, int y, int reset);
int next_list_ground(char *buffer, int *pos1, int pos2, int *stage);
int set_pos_y(char *str);

// src/ground/ground.c
char **init_ground(void);
object_t **set_object(void);
void ground(game_t *game);

// src/music/music.c
void play_music(game_t *game);
void mute_music(game_t *game);
void pause_music(game_t *game);
void stop_music(game_t *game);

// src/parallax/parallax.c
char **init_png(void);
parallax_t **set_png(int x, int y);
void move(sfSprite *sprite, sfVector2f pos_init, int value);
void move_parallax(parallax_t **bg);
void parallax(game_t *game);

// src/players/choose_player.c
ch_pl_t *pls(char *filename, sfVector2f pos, sfVector2f scale);
char **initt_player(void);
ch_pl_t **ress_pl(void);
void display_menu_players(game_t *game);

// src/players/collision.c
int object_collision(game_t *game);
void game_over(game_t *game);
void victory(game_t *game);

// src/players/player.c
char **init_player(void);
int jump_players(game_t *game, float velocity);
player_t **set_player(void);
void display_players(game_t *game);

// src/players/players_texts.c
void players_texts(game_t *game);
void draw_player_texts(game_t *game);

// src/utilities/utilities.c
char *int_to_char(int nb);

// src/utilities/utilities_sfml.c
parallax_t *init_parallax(char *filepath, sfVector2f my_pos, sfIntRect rect);
object_t *obj(char *filepath, sfIntRect rect);
sfVector2f position(int x, int y);
int pressed_or_not(sfSprite *sprite, sfVector2f pos, const int size);
player_t *anm(char *filepath, sfVector2f pos, sfVector2f sc, sfIntRect rect);

// src/window/menu_display.c
void draw_start(game_t *game);
void draw_game(game_t *game, char *argv);
void draw_mnu_players(game_t *game);
void draw_end(game_t *game);
void draw_victory(game_t *game);

// src/window/menu_texts.c
void load_font( game_t *game);
sfText *get_text(sfVector2f pos, char *sentence, int size, sfFont *font);
void menu_texts(game_t *game);
void draw_texts_start(game_t *game);
void draw_texts_end(game_t *game);

// src/window/menu.c
bg_menu_t *bg_window(void);
window_t *window(char *filename, sfVector2f pos, sfVector2f scale);
char **init_menu(void);
window_t **resource_menu(void);
void display_menu(game_t *game);

// src/window/victory.c
void draw_text_victory(game_t *game);

// src/init_struct.c
game_next_t *init_game_next(void);
game_t *init_game(char *argv);
option_t *init_option(void);

// src/select_mode.c
int select_mode_2(game_t *game, char *str);
void select_mode_next(game_t *game);
void select_mode(game_t *game, char *av);

// src/usage.c
int help(void);

// src/clock.c
void clock_next(game_t *game);
void clock(game_t *game);

#endif /* !RUNNER_H_ */
