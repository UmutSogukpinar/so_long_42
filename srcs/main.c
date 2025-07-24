#include "../includes/game.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		display_error_msg(INV_ARGC, false);
		return (EXIT_FAILURE);
	}
	if (!is_file_extension_proper(argv[1], MAP_FILE_EXTENSION))
		return (EXIT_FAILURE);
	game = init_game(argv[1]);
	if (!game)
		return (EXIT_FAILURE);
	debug_game_state(game);
	if (!execute_game(game))
	{
		free_game(game);
		return (EXIT_FAILURE);
	}
	free_game(game);
	return (EXIT_SUCCESS);
}
