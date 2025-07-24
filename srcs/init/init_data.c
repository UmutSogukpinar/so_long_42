#include "../../includes/game.h"

static bool	set_player(t_game *game, int x, int y);

bool	init_data(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (game->map.matrix[i])
	{
		j = 0;
		while (game->map.matrix[i][j])
		{
			c = game->map.matrix[i][j];
			if (c == PLAYER && !set_player(game, j, i))
				return (false);
			else if (c == COLL)
				game->data.total_collectible++;
			else if (c == EXIT)
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
