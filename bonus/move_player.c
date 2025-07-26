#include "../includes/game.h"
#include "../includes/game_bonus.h"

static bool	handle_exit(t_game *game, char tile);
static bool is_walkable(t_game *game, t_axis delta);
static void update_player(t_player *player, t_axis delta);
static void	handle_collectible(t_game *game, int x, int y);

void	move_player(t_game *game, t_axis delta)
{
	int		new_x;
	int		new_y;
	char	next;

	new_x = game->player.pos.x + delta.x;
	new_y = game->player.pos.y + delta.y;
	if (!is_walkable(game, delta))
		return ;
	if (is_enemy_collision(game, new_x, new_y))
	{
		printf("You were caught by an enemy! Game over.\n");
		handle_close(game);
		return ;
	}
	next = game->map.matrix[new_y][new_x];
	if (next == COLL)
		handle_collectible(game, new_x, new_y);
	if (handle_exit(game, next))
		return ;
	update_player(&game->player, delta);
	if (game->data.move_count < SIZE_MAX)
		game->data.move_count++;

}

static void update_player(t_player *player, t_axis delta)
{
	player->pos.x += delta.x;
	player->pos.y += delta.y;
}

static void	handle_collectible(t_game *game, int x, int y)
{
	game->player.gathered_collectible++;
	game->map.matrix[y][x] = FLOOR;
}

static bool	handle_exit(t_game *game, char tile)
{
	if (tile != EXIT)
		return (false);
	if (game->player.gathered_collectible == game->data.total_collectible)
	{
		if (game->data.move_count < SIZE_MAX)
			game->data.move_count++;
		handle_close(game);
	}
	return (true);
}

static bool is_walkable(t_game *game, t_axis d)
{
	int     new_x = game->player.pos.x + d.x;
	int     new_y = game->player.pos.y + d.y;
	char    tile;

	if (new_x < 0 || new_y < 0
		|| (size_t)new_x >= game->map.width
		|| (size_t)new_y >= game->map.height)
		return (false);

	tile = game->map.matrix[new_y][new_x];
	return (tile == FLOOR || tile == COLL || tile == EXIT);
}
