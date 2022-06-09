##
## EPITECH PROJECT, 2020
## delivery
## File description:
## Makefile
##

SRC =	src/my_runner.c \
		src/select_mode.c \
		src/usage.c \
		src/utilities/utilities.c \
		src/utilities/utilities_sfml.c \
		src/parallax/parallax.c \
		src/event/mouse_event_players.c \
		src/event/window_event.c \
		src/event/window.c \
		src/ground/ground.c \
		src/ground/gen_ground.c \
		src/ground/gen_ground_next.c \
		src/window/menu.c \
		src/window/menu_display.c \
		src/window/menu_texts.c \
		src/window/victory.c \
		src/music/music.c \
		src/init_struct.c \
		src/players/player.c \
		src/players/choose_player.c \
		src/players/collision.c \
		src/players/players_texts.c \
		src/clock.c

OBJ = 	$(SRC:.c=.o)

NAME = 	my_runner

CFLAGS = -g

all: 	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
