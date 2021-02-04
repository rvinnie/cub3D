CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

NAME		=	cub3D

SRCS		=	main.c \
				parser/parser.c \
				painter/painter.c \
				painter/paint_map.c \
				gnl/get_next_line_utils.c \
				gnl/get_next_line.c \
				libft/lst_funcs.c \
				utils/error_handler.c
				

OBJS		=	$(SRCS:.c=.o)

# %.o:%.c
# 	$(CC) -Wall -Wextra -Werror -I./includes -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L.mlx -lmlx_Linux -lXext -lX11 -lm -lz

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