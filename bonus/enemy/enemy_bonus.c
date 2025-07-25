#include "../../includes/game.h"
#include "../../includes/game_bonus.h"

static void	update_enemy_frame(t_enemy *enemy);

void	update_enemies(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->data.enemy_count)
	{
		move_enemy(game, &game->enemies[i]);
		update_enemy_frame(&game->enemies[i]);
		i++;
	}
}

static void	update_enemy_frame(t_enemy *enemy)
{
	enemy->frame_tick++;
	if (enemy->frame_tick >= FRAME_DELAY)
	{
		enemy->frame = (enemy->frame + 1) % ENEMY_ANIM_FRAME;
		enemy->frame_tick = 0;
	}
}
