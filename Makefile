# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

# Project name
NAME    = so_long
BONUS_NAME = so_long_bonus

# Directories
SRC_DIR = srcs
LIBFT_DIR = libs/libft
MLX_DIR  = libs/mlx
BONUS_DIR  = bonus

# Subdirectories
INIT_DIR = $(SRC_DIR)/init
FREE_DIR = $(SRC_DIR)/free
CHECKER_DIR = $(SRC_DIR)/checkers
EVENT_DIR = $(SRC_DIR)/events
UTILS_DIR = $(SRC_DIR)/utils
GNL_DIR = $(SRC_DIR)/gnl

# Bonus subdirectories


# Libraries
LIBS = $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a -lXext -lX11 -lm

# Headers
INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)

# Source Files
SRCS =										\
		$(SRC_DIR)/main.c					\
		$(INIT_DIR)/init_game.c				\
		$(INIT_DIR)/init_data.c				\
		$(INIT_DIR)/init_map.c				\
		$(INIT_DIR)/init_mlx.c				\
		$(INIT_DIR)/init_texture.c			\
		$(FREE_DIR)/free.c					\
		$(CHECKER_DIR)/map_checker.c		\
		$(CHECKER_DIR)/file_checker.c		\
		$(EVENT_DIR)/loop.c					\
		$(EVENT_DIR)/draw.c					\
		$(EVENT_DIR)/move.c					\
		$(UTILS_DIR)/display.c				\
		$(UTILS_DIR)/str_utils.c			\
		$(UTILS_DIR)/debug.c				\
		$(GNL_DIR)/get_next_line.c			\
		$(GNL_DIR)/get_next_line_utils.c	\




# Bonus Source Files
BONUS_SRCS = 							\

# Default target
all: $(NAME)

bonus: $(BONUS_NAME)

# Build target
$(NAME): $(SRCS)
	@$(MAKE) -C $(LIBFT_DIR) --silent
	@$(MAKE) -C $(MLX_DIR) --silent || true
	@$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)
	@echo "✅ Build complete!"

$(BONUS_NAME): $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) --silent
	@$(MAKE) -C $(MLX_DIR) --silent || true
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBS) -o $(NAME)
	@echo "✅ Bonus build complete!"

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@$(MAKE) -C $(MLX_DIR) clean --silent || true
	@echo "🧹 Clean complete!"

# Clean everything
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent
	@echo "🧼 Full clean!"

# Recompile
re: fclean all

.PHONY: all clean fclean re
