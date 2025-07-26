#ifndef GAME_BONUS_H
# define GAME_BONUS_H

# include "structures.h"

// ======================= Enemy Functions =======================

void	draw_move_counter(t_game *game);
bool	init_counter_textures(t_game *game);

void	update_enemies(t_game *game);
void	move_enemy(t_game *game, t_enemy *enemy);

bool    is_enemy_collision(t_game *game, int x, int y);

t_ms	get_current_time_ms(void);
t_ms	get_elapsed_ms(t_game *game);

#endif