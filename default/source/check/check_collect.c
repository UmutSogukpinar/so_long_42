#include "so_long.h"

int	all_collectibles_gathered(t_game *game)
{
	if (game -> total_collectible == game -> gathered_collectible)
		return (1);
	else
		return (0);
}
