#ifndef GAME_H
# define GAME_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>

# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"

# include "structures.h"
# include "error_logs.h"
# include "get_next_line.h" 


// ======================= Initialization Functions =======================

t_game	*init_game(char	*map_path);
bool	init_map(t_game *game);
bool	init_data(t_game *game);
bool    init_mlx(t_game *game);
bool    init_textures(t_game *game);

// ======================= Event Functions =======================

void    draw_map(t_game *game);
bool    execute_game(t_game *game);
int     handle_close(t_game *game);
void	move_player(t_game *game, t_axis delta);

// ========================== Free Functions ==========================

void	free_tab(char **ptr);
void	free_game(t_game *game);

// ========================= Checker Functions =========================

bool	check_data(t_game *game);
bool	is_map_valid(t_game *game);
bool    is_map_accessable(t_game *game);
bool	is_file_extension_proper(char *file, char *extension);

// ========================= Display Functions =========================

bool	display_error_msg(char *msg, bool is_perror);
void	display_count_move(int count);

// ============================= Utils =============================

bool	is_space(char c);
void	ft_rtrim(char *str);
char	**copy_matrix(t_game *game, char **matrix);
bool	is_map_element(char c);

// ! Delete Later
void	debug_game_state(t_game *game);

#endif