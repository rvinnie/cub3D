CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

NAME		=	cub3D

SRCS		=	main.c \
				parser/parser.c \
				gnl/get_next_line_utils.c \
				gnl/get_next_line.c \
				libft/lst_funcs.c \
				utils/error_handler.c
				

OBJS		=	$(SRCS:.c=.o)

# %.o: %.c
#     $(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@


$(NAME): $(OBJS)                            
	$(CC) $(OBJS) $(CFLAGS) -I/usr/include -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lmlx -lX11 -lm -lz -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re 