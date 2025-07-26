#include "../includes/game.h"
#include "../includes/game_bonus.h"

static void *get_tile_img(t_game *game, char tile);
static void draw_enemy(t_game *game, int x, int y);
static void draw_player(t_game *game, int x, int y);
static void draw_tile(t_game *game, size_t i, size_t j);

void draw_map(t_game *game)
{
	size_t i;
	size_t j;

    i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			draw_tile(game, i, j);
			j++;
		}
		i++;
	}
}

static void *get_tile_img(t_game *game, char tile)
{
	if (tile == WALL)
		return (game->textures.wall.img);
	if (tile == FLOOR)
		return (game->textures.floor.img);
	if (tile == COLL)
		return (game->textures.collectible.img);
	if (tile == EXIT)
		return (game->textures.exit.img);
	return (game->textures.floor.img);
}

static void draw_tile(t_game *game, size_t i, size_t j)
{
	char	tile;
	void	*img;
	int		x;
	int		y;

	tile = game->map.matrix[i][j];
	img = get_tile_img(game, tile);
	x = (int)j;
	y = (int)i;
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, img, x * SIZE, y * SIZE);
	draw_player(game, x, y);
	draw_enemy(game, x, y);
	draw_move_counter(game);
}

static void draw_player(t_game *game, int x, int y)
{
	void *player_img;

	if (game->player.pos.x == x && game->player.pos.y == y)
	{
		player_img = game->player.textures[game->player.dir].img;
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, player_img, x * SIZE, y * SIZE);
	}
}

static void draw_enemy(t_game *game, int x, int y)
{
	size_t	i;
	t_enemy	*enemy;
	void	*enemy_img;

	i = 0;
	while (i < game->data.enemy_count)
	{
		enemy = &game->enemies[i];
		if (enemy->pos.x == x && enemy->pos.y == y)
		{
			enemy_img = game->enemy_texture.textures[enemy->dir][enemy->frame].img;
			mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, enemy_img, x * SIZE, y * SIZE);
		}
		i++;
	}
}
