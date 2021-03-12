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

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g

NAME		=	cub3D

SRCS		=	main.c \
				parser/main_parser.c \
				parser/player_parser.c \
				parser/sprite_parser.c \
				parser/texture_parser.c \
				parser/info_parser.c \
				parser/map_parser.c \
				parser/map_checker.c \
				game_graphics/painter.c \
				game_graphics/main_drawer.c \
				game_graphics/raycasting.c \
				game_graphics/draw_line.c \
				game_graphics/find_walls.c \
				textures/texture_slice.c \
				moving/change_degree.c \
				moving/make_step.c \
				gnl/get_next_line_utils.c \
				gnl/get_next_line.c \
				libft/lst_funcs.c \
				libft/find_chr.c \
				libft/ft_split.c \
				libft/ft_strncmp.c \
				libft/ft_atoi.c \
				libft/ft_isdigit.c \
				libft/ft_calloc.c \
				utils/error_handler.c \
				utils/dir_to_degree.c \
				utils/rgb_to_hex.c \
				utils/trigonometry_funcs.c \
				utils/check_border.c \
				utils/lst_to_arr.c \
				cleaner/free_arr.c

OBJS		=	$(SRCS:.c=.o)

# %.o:%.c
# 	$(CC) -Wall -Wextra -Werror -I./includes -Imlx_linux -O3 -c $< -o $@

# $(NAME): $(OBJS)
	# $(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L.mlx -lmlx_Linux -lXext -lX11 -lm -lz


$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -O3 -o$(NAME)

all:	$(NAME)

test:
	$(CC) -c testing/test.c
	$(CC) -o test test.o -L.mlx -lmlx_Linux -lXext -lX11 -lm -lz
	$(RM) test.o
	mv test testing
	./testing/test

testc:
	$(RM) test

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re 
