/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:10:50 by umut              #+#    #+#             */
/*   Updated: 2024/12/28 22:20:48 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "mlx.h"
#include "libft.h"
#include "map.h"
#include "draw.h"

int	close_window(void *param)
{
	t_game	*game;

	if (param == NULL)
	{
		perror("Param is null");
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
	game -> mlx = NULL;
	game -> screen = NULL;
	game -> player = NULL;
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
		perror("Invalid number of argument");
		return (-1);
	}
	init_game(game, args);
	mlx_key_hook(game -> screen, key_hook, game);
	mlx_loop(game -> mlx);
	close_window(game);
	return (0);
}
