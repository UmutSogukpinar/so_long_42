#include "../../includes/game.h"

static bool init_mlx_ptr(t_mlx *mlx);
static bool init_window(t_mlx *mlx);
static bool init_image(t_mlx *mlx);

bool init_mlx(t_game *game)
{
    game->mlx = ft_calloc(1, sizeof(t_mlx));
    if (!game->mlx)
        return (display_error_msg(MLX_ERR, true));
    game->mlx->width  = (int)(game->map.width  * SIZE);
    game->mlx->height = (int)(game->map.height * SIZE);
    if (!init_mlx_ptr(game->mlx) || !init_window(game->mlx) || !init_image(game->mlx))
        return (false);
    return (true);
}

static bool init_mlx_ptr(t_mlx *mlx)
{
    mlx->mlx = mlx_init();
    if (!mlx->mlx)
        return (display_error_msg(MLX_ERR, true));
    return (true);
}

static bool init_window(t_mlx *mlx)
{
    mlx->win = mlx_new_window(
        mlx->mlx,
        mlx->width,
        mlx->height,
        GAME_NAME
    );
    if (!mlx->win)
        return (display_error_msg(MLX_ERR, true));
    return (true);
}

static bool init_image(t_mlx *mlx)
{
    mlx->img = mlx_new_image(
        mlx->mlx,
        mlx->width,
        mlx->height
    );
    if (!mlx->img)
        return (display_error_msg(MLX_ERR, true));
    mlx->addr = mlx_get_data_addr(
        mlx->img,
        &mlx->bpp,
        &mlx->line_len,
        &mlx->endian
    );
    return (true);
}
