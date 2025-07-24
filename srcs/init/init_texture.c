#include "../../includes/game.h"

static bool load_texture(void *mlx_ptr, t_texture *tex, char *path);

bool init_textures(t_game *game)
{
    void *mlx_ptr = game->mlx->mlx;

    if (
        !load_texture(mlx_ptr, &game->textures.wall,          WALL_PATH)        ||
        !load_texture(mlx_ptr, &game->textures.floor,         FLOOR_PATH)       ||
        !load_texture(mlx_ptr, &game->textures.collectible,   COLLECTIBLE_PATH) ||
        !load_texture(mlx_ptr, &game->textures.exit,          EXIT_PATH)        ||
        !load_texture(mlx_ptr, &game->player.textures[UP],    PLAYER_U_PATH)    ||
        !load_texture(mlx_ptr, &game->player.textures[DOWN],  PLAYER_D_PATH)    ||
        !load_texture(mlx_ptr, &game->player.textures[LEFT],  PLAYER_L_PATH)    ||
        !load_texture(mlx_ptr, &game->player.textures[RIGHT], PLAYER_R_PATH)
    )
    {
        return (false);
    }
    return (true);
}

static bool load_texture(void *mlx_ptr, t_texture *tex, char *path)
{
    if (!is_file_extension_proper(path, ASSET_FILE_EXTENSION))
    {
        return (display_error_msg(INV_ASSET_EXT, false));
    }
    tex->img = mlx_xpm_file_to_image(
        mlx_ptr,
        path,
        &tex->width,
        &tex->height
    );
    if (!tex->img)
        return (display_error_msg(TEXTURE_ERR, true));
    tex->addr = mlx_get_data_addr(
        tex->img,
        &tex->bpp,
        &tex->line_len,
        &tex->endian
    );
    return (true);
}
