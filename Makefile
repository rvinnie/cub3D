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
				parser/parser.c \
				game_graphics/painter.c \
				game_graphics/paint_map.c \
				game_graphics/raycasting.c \
				game_graphics/draw_line.c \
				game_graphics/find_walls.c \
				moving/change_degree.c \
				moving/make_step.c \
				gnl/get_next_line_utils.c \
				gnl/get_next_line.c \
				libft/lst_funcs.c \
				libft/find_chr.c \
				utils/error_handler.c \
				utils/dir_to_degree.c \
				utils/trigonometry_funcs.c \
				utils/check_border.c

OBJS		=	$(SRCS:.c=.o)

# %.o:%.c
# 	$(CC) -Wall -Wextra -Werror -I./includes -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L.mlx -lmlx_Linux -lXext -lX11 -lm -lz


# $(NAME):	$(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) // MAC

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
