NAME = so_long

SOURCE_DIR = ./source
DRAW_DIR = source/draw
MAP_DIR  = source/map
MOVE_DIR = source/movement
LIBFT_DIR = ./libs/my_libft
PRINTF_DIR = ./libs/my_printf
MLX_DIR = ./libs/mlx

SRCS =	$(SOURCE_DIR)/main.c \
		$(SOURCE_DIR)/free.c \
		$(SOURCE_DIR)/init.c \
		$(SOURCE_DIR)/key_hook.c \
		$(MAP_DIR)/init_map.c \
		$(DRAW_DIR)/draw_map.c \
		$(DRAW_DIR)/init_images_one.c \
		$(MOVE_DIR)/movement.c \
		$(MOVE_DIR)/check.c \

OBJS = ${SRCS:.c=.o}

CC = cc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(PRINTF_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a  $(MLX_FLAGS) -o $(NAME)

clean:
	${RM} ${OBJS}
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) fclean

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re