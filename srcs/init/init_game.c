#include "../../includes/game.h"

static void player_ctor(t_player *player);

t_game	*init_game(char	*map_path)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		display_error_msg(INIT_ERR, true);
		return (NULL);
	}
	game->map.path = map_path; 
	game->name = GAME_NAME;
	player_ctor(&game->player);
	if (!init_map(game) || !is_map_valid(game) ||
		!init_data(game) || !is_map_accessable(game) ||
		!init_mlx(game) || !init_textures(game))
	{
		free_game(game);
		return (NULL);
	}
	return (game);
}

static void player_ctor(t_player *player)
{
	player->pos.x = NPOS;
	player->pos.y = NPOS;
	player->gathered_collectible = 0;
}
