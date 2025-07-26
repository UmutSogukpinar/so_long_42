#include "../../includes/game.h"
#include "../../includes/game_bonus.h"


static bool	load_texture(void *mlx_ptr, t_texture *tex, char *path);
static bool	init_player_textures(t_game *game);
static bool	init_environment_textures(t_game *game);
static bool	init_enemy_textures(t_game *game);

bool	init_textures(t_game *game)
{
	if (!init_environment_textures(game))
		return (false);
	if (!init_player_textures(game))
		return (false);
	if (!init_enemy_textures(game))
		return (false);
	if (!init_counter_textures(game))
		return (false);
	return (true);
}

static bool	load_texture(void *mlx_ptr, t_texture *tex, char *path)
{
	if (!is_file_extension_proper(path, ASSET_FILE_EXTENSION))
		return (display_error_msg(INV_ASSET_EXT, false));
	tex->img = mlx_xpm_file_to_image(mlx_ptr, path, &tex->width, &tex->height);
	if (!tex->img)
		return (display_error_msg(TEXTURE_ERR, true));
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_len, &tex->endian);
	return (true);
}

static bool	init_environment_textures(t_game *game)
{
	void	*mlx;

	mlx = game->mlx->mlx;
	return (
		load_texture(mlx, &game->textures.wall, WALL_PATH)
		&& load_texture(mlx, &game->textures.floor, FLOOR_PATH)
		&& load_texture(mlx, &game->textures.collectible, COLLECTIBLE_PATH)
		&& load_texture(mlx, &game->textures.exit, EXIT_PATH)
	);
}


static bool	init_player_textures(t_game *game)
{
	void	*mlx;

	mlx = game->mlx->mlx;
	return (
		load_texture(mlx, &game->player.textures[UP], PLAYER_U_PATH)
		&& load_texture(mlx, &game->player.textures[DOWN], PLAYER_D_PATH)
		&& load_texture(mlx, &game->player.textures[LEFT], PLAYER_L_PATH)
		&& load_texture(mlx, &game->player.textures[RIGHT], PLAYER_R_PATH)
	);
}

static bool	init_enemy_textures(t_game *game)
{
	void *mlx = game->mlx->mlx;

	return (
		load_texture(mlx, &game->enemy_texture.textures[DOWN][0], ENEMY_D_0_PATH) &&
		load_texture(mlx, &game->enemy_texture.textures[DOWN][1], ENEMY_D_1_PATH) &&
		load_texture(mlx, &game->enemy_texture.textures[DOWN][2], ENEMY_D_2_PATH) &&
		load_texture(mlx, &game->enemy_texture.textures[DOWN][3], ENEMY_D_3_PATH) &&

		load_texture(mlx, &game->enemy_texture.textures[LEFT][0], ENEMY_L_0_PATH) &&
		load_texture(mlx, &game->enemy_texture.textures[LEFT][1], ENEMY_L_1_PATH) &&
		load_texture(mlx, &game->enemy_texture.textures[LEFT][2], ENEMY_L_2_PATH) &&
		load_texture(mlx, &game->enemy_texture.textures[LEFT][3], ENEMY_L_3_PATH) &&

		load_texture(mlx, &game->enemy_texture.textures[RIGHT][0], ENEMY_R_0_PATH) &&
		load_texture(mlx, &game->enemy_texture.textures[RIGHT][1], ENEMY_R_1_PATH) &&
		load_texture(mlx, &game->enemy_texture.textures[RIGHT][2], ENEMY_R_2_PATH) &&
		load_texture(mlx, &game->enemy_texture.textures[RIGHT][3], ENEMY_R_3_PATH) &&

		load_texture(mlx, &game->enemy_texture.textures[UP][0], ENEMY_U_0_PATH) &&
		load_texture(mlx, &game->enemy_texture.textures[UP][1], ENEMY_U_1_PATH) &&
		load_texture(mlx, &game->enemy_texture.textures[UP][2], ENEMY_U_2_PATH) &&
		load_texture(mlx, &game->enemy_texture.textures[UP][3], ENEMY_U_3_PATH)
	);
}


