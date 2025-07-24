#include "../../includes/game.h"

static void free_mlx(t_game *game);
static void free_textures(t_game *game);

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_tab(game->map.matrix);
	free_mlx(game);
	free(game);
}

void	free_tab(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static void free_mlx(t_game *game)
{
    t_mlx *mlx;

    if (!game->mlx || !game->mlx->mlx)
        return;
    mlx = game->mlx;
	free_textures(game);
    if (mlx->img)
        mlx_destroy_image(mlx->mlx, mlx->img);
    if (mlx->win)
        mlx_destroy_window(mlx->mlx, mlx->win);
    mlx_destroy_display(mlx->mlx);
    free(mlx->mlx);
    free(mlx);
    game->mlx = NULL;
}

static void free_textures(t_game *game)
{
	void	*mlx_ptr;
    
	mlx_ptr = game->mlx->mlx;
	if (!mlx_ptr)
		return ;

    if (game->textures.wall.img)
        mlx_destroy_image(mlx_ptr, game->textures.wall.img);
    if (game->textures.floor.img)
        mlx_destroy_image(mlx_ptr, game->textures.floor.img);
    if (game->textures.collectible.img)
        mlx_destroy_image(mlx_ptr, game->textures.collectible.img);
    if (game->textures.exit.img)
        mlx_destroy_image(mlx_ptr, game->textures.exit.img);
    if (game->player.textures[UP].img)
        mlx_destroy_image(mlx_ptr, game->player.textures[UP].img);
    if (game->player.textures[DOWN].img)
        mlx_destroy_image(mlx_ptr, game->player.textures[DOWN].img);
    if (game->player.textures[LEFT].img)
        mlx_destroy_image(mlx_ptr, game->player.textures[LEFT].img);
    if (game->player.textures[RIGHT].img)
        mlx_destroy_image(mlx_ptr, game->player.textures[RIGHT].img);
}

