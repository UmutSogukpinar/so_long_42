NAME = so_long

SOURCE_DIR = ./source
DRAW_DIR = source/draw
MAP_DIR  = source/map
LIBFT_DIR = ./libs/my_libft
MLX_DIR = ./libs/mlx

SRCS =	$(SOURCE_DIR)/main.c \
		$(SOURCE_DIR)/free.c \
		$(MAP_DIR)/init_map.c \
		$(DRAW_DIR)/ground.c \

OBJS = ${SRCS:.c=.o}

CC = cc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)

clean:
	${RM} ${OBJS}
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
