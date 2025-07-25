#include "../../includes/game.h"

static void *get_tile_img(t_game *game, char tile);
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
	void    *img;
	int     x;
	int     y;
    void    *player_img;

    tile = game->map.matrix[i][j];
    img = get_tile_img(game, tile);
    x = (int)(j * SIZE);
	y = (int)(i * SIZE);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, img, x, y);
	if (game->player.pos.x == (int)j && game->player.pos.y == (int)i)
	{
		player_img = game->player.textures[game->player.dir].img;
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, player_img, x, y);
	}
}

