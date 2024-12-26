/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:10:50 by umut              #+#    #+#             */
/*   Updated: 2024/12/27 00:32:22 by umut             ###   ########.fr       */
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
		free(game);
	}
	exit(EXIT_SUCCESS);
}

int	main(int arg_number, char **args)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	if (arg_number != 2)
	{
		perror("Invalid number of argument");
		return (-1);
	}
	init_game(game, args);
	mlx_loop(game -> mlx);
	free_game(game);
	free(game);
	return (0);
}
