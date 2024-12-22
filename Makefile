NAME = so_long

DRAW_DIR = source/draw
MAP_DIR  = source/map
MLX_DIR = ./mlx

SRCS =	source/main.c \
		${MAP_DIR}/init_map.c \


OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibs/my_libft -Imlx

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./libs/my_libft
	${CC} ${CFLAGS} ${OBJS} ./libs/my_libft/libft.a -o ${NAME}

clean:
	${RM} ${OBJS}
	${MAKE} -C ./libs/my_libft fclean

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
