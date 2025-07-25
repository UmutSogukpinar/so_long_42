#include "../includes/game.h"
#include "../includes/game_bonus.h"

static bool	set_player(t_game *game, int x, int y);
static bool set_enemy(t_game *game, int x, int y);
static bool enemies_realloc(t_game *game, t_enemy new_enemy);

bool	init_data(t_game *game, char **matrix)
{
	int		i;
	int		j;

	i = 0;
	while (game->map.matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == PLAYER && !set_player(game, j, i))
				return (false);
            else if (matrix[i][j] == ENEMY && !set_enemy(game, j, i))
                return (false);
			else if (matrix[i][j] == COLL)
				game->data.total_collectible++;
			else if (matrix[i][j] == EXIT)
				game->data.exit_count++;
			else if (!is_map_element(game->map.matrix[i][j]) &&
						matrix[i][j] != ENEMY)
				return (display_error_msg(INV_MAP_EL, false));
			j++;
		}
		i++;
	}
	return (check_data(game));
}

static bool	set_player(t_game *game, int x, int y)
{
	if (game->player.pos.x != NPOS || game->player.pos.y != NPOS)
	{
		return (display_error_msg(MULTI_PLAYER_ERR, false));
	}
	game->player.pos.x = x;
	game->player.pos.y = y;
	game->map.matrix[y][x] = FLOOR;
	return (true);
}

static bool set_enemy(t_game *game, int x, int y)
{
    t_enemy new_enemy;

    new_enemy.frame = 0;
	new_enemy.frame_tick = 0;
    new_enemy.pos.x = x;
    new_enemy.pos.y = y;
    new_enemy.dir = rand() % 4;
    if (!enemies_realloc(game, new_enemy))
        return (false);
    return (true);
}

static bool enemies_realloc(t_game *game, t_enemy new_enemy)
{
	t_enemy	*new_list;
	size_t	i;

	new_list = ft_calloc(game->data.enemy_count, sizeof(t_enemy));
	if (!new_list)
		return (display_error_msg(INIT_ERR, true));
	i = 0;
	while (game->enemies && i < game->data.enemy_count)
	{
		new_list[i] = game->enemies[i];
		i++;
	}
	new_list[i] = new_enemy;
	if (game->enemies)
		free(game->enemies);
	game->enemies = new_list;
    game->data.enemy_count++;
	return (true);
}
