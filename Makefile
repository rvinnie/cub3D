# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 17:29:43 by rvinnie           #+#    #+#              #
#    Updated: 2021/02/08 17:29:45 by rvinnie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror

LFLAGS		=	-lXext -lX11 -lm -lz

LIBMLX		=	libs/libmlx.a libs/libft.a

HEADER		=	cub3d.h

NAME		=	cub3D

SRCS		=	main.c \
				parser/main_parser.c \
				parser/player_parser.c \
				parser/sprite_parser.c \
				parser/texture_parser.c \
				parser/info_parser.c \
				parser/map_parser.c \
				parser/map_checker.c \
				parser/map_checker_second.c \
				game_graphics/painter.c \
				game_graphics/main_drawer.c \
				game_graphics/raycasting.c \
				game_graphics/find_walls.c \
				game_graphics/sprite_handler.c \
				game_graphics/screenshot.c \
				game_graphics/texture_slice.c \
				game_graphics/choose_texture.c \
				moving/change_degree.c \
				moving/make_step.c \
				gnl/get_next_line_utils.c \
				gnl/get_next_line.c \
				utils/lst_funcs.c \
				utils/find_chr.c \
				utils/dir_to_degree.c \
				utils/rgb_to_hex.c \
				utils/trigonometry_funcs.c \
				utils/check_border.c \
				utils/lst_to_arr.c \
				utils/sort_sprites.c \
				exit/free_arr.c \
				exit/exit_game.c \
				exit/error_handler.c

OBJS		=	$(SRCS:.c=.o)

$(NAME):	$(OBJS) $(HEADER)
	$(CC) $(OBJS) $(LIBMLX) $(LFLAGS) -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

all:	$(NAME)

clean:
	$(RM) $(OBJS) cub3D.dSYM

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re 
