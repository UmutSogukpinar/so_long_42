/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:59:21 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/30 19:06:22 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "map.h"
#include "check.h"
#include "draw.h"
#include "ft_printf.h"

int	close_window(void *param)
{
	t_game	*game;

	if (param == NULL)
	{
		ft_printf("Param is null. Game shut down\n");
		exit(EXIT_FAILURE);
	}
	(void)param;
	game = (t_game *)param;
	if (game)
	{
		free_game(game);
		free(game -> player);
		free(game);
	}
	exit(EXIT_SUCCESS);
}

void	init_game_structure(t_game *game, t_player *player)
{
	game -> name = NULL;
	game -> filename = NULL;
	game -> map = NULL;
	game -> ground_img = NULL;
	game -> wall_img = NULL;
	game -> collect_img = NULL;
	game -> enemy_img = NULL;
	game -> exit_img = NULL;
	game -> mlx = NULL;
	game -> screen = NULL;
	player -> img = NULL;
	game -> player = player;
}

int	main(int arg_number, char **args)
{
	t_game		*game;
	t_player	*player;

	game = malloc(sizeof(t_game));
	player = malloc(sizeof(t_player));
	init_game_structure(game, player);
	if (!game)
		return (0);
	if (arg_number != 2)
	{
		ft_printf("Invalid number of argument. Game shuts down\n");
		return (-1);
	}
	init_game(game, args);
	game_check(game);
	mlx_key_hook(game -> screen, key_hook, game);
	mlx_loop(game -> mlx);
	close_window(game);
	return (0);
}
