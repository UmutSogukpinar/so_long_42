#include "../../includes/game.h"

static bool	set_player(t_game *game, int x, int y);

bool	init_data(t_game *game, char **matrix)
{
	int		i;
	int		j;

	while (game->map.matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == PLAYER && !set_player(game, j, i))
				return (false);
			else if (matrix[i][j] == COLL)
				game->data.total_collectible++;
			else if (matrix[i][j] == EXIT)
				game->data.exit_count++;
			else if (!is_map_element(game->map.matrix[i][j]))
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
