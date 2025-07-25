#include "../../includes/game.h"
#include "../../includes/game_bonus.h"

static t_axis	get_next_pos(t_enemy *enemy);
static bool		is_tile_blocked(t_game *game, t_axis pos);
static bool		is_enemy_at(t_game *game, t_enemy *current, t_axis pos);
static bool		is_player_at(t_game *game, t_axis pos);
static int		get_new_direction_excluding(int exclude);

void	move_enemy(t_game *game, t_enemy *enemy)
{
	t_axis	next;

	next = get_next_pos(enemy);
	if (is_tile_blocked(game, next) || is_enemy_at(game, enemy, next))
	{
		enemy->dir = get_new_direction_excluding(enemy->dir);
		return ;
	}
	if (is_player_at(game, next))
	{
		printf("Game Over! You were caught by an enemy.\n");
		handle_close(game);
	}
	enemy->pos = next;
}

static t_axis	get_next_pos(t_enemy *enemy)
{
	t_axis	next;

	next = enemy->pos;
	if (enemy->dir == UP)
		next.y--;
	else if (enemy->dir == DOWN)
		next.y++;
	else if (enemy->dir == LEFT)
		next.x--;
	else if (enemy->dir == RIGHT)
		next.x++;
	return (next);
}

static bool	is_tile_blocked(t_game *game, t_axis pos)
{
	if (pos.y < 0 || pos.y >= (int)game->map.height ||
		pos.x < 0 || pos.x >= (int)game->map.width)
		return (true);
	if (game->map.matrix[pos.y][pos.x] == WALL ||
		game->map.matrix[pos.y][pos.x] == COLL)
		return (true);
	return (false);
}

static bool	is_enemy_at(t_game *game, t_enemy *current, t_axis pos)
{
	size_t	i;

	i = 0;
	while (i < game->data.enemy_count)
	{
		if (&game->enemies[i] != current &&
			game->enemies[i].pos.x == pos.x &&
			game->enemies[i].pos.y == pos.y)
			return (true);
		i++;
	}
	return (false);
}

static bool	is_player_at(t_game *game, t_axis pos)
{
	return (pos.x == game->player.pos.x && pos.y == game->player.pos.y);
}

static int	get_new_direction_excluding(int exclude)
{
	int	options[NUMBER_OF_DIR - 1];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < NUMBER_OF_DIR)
	{
		if (i != exclude)
		{
			options[j] = i;
			j++;
		}
		i++;
	}
	return (options[rand() % (NUMBER_OF_DIR - 1)]);
}
