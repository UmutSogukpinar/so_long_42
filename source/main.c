/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:10:50 by umut              #+#    #+#             */
/*   Updated: 2024/12/26 10:31:09 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/mlx/mlx.h"
#include "so_long.h"
#include "map.h"
#include "libft.h"
#include "../libs/my_printf/ft_printf.h"
#include "draw.h"
#include "stdio.h"

int	close_window(void *param)
{
	t_game	*game;

	if (param == NULL)
	{
		ft_printf("param is NULL\n");
		exit(1);
	}
	(void)param;
	game = (t_game *)param;
	if (game)
	{
		free_game(game);
		free(game);
	}
	exit(0);
}

int	init_game_att(t_game *game, char *arg)
{
	int	is_successful;

	game -> filename = ft_strdup(arg);
	game -> moves = 0;
	game -> screen_y = (count_lines(game -> filename) * CELL_LEN);
	game -> screen_x = (count_columns(game -> filename) * CELL_LEN);
	game -> name = ft_strdup("so_long");
	is_successful = init_map(game);
	if (is_successful == -1 || !(game -> name) || !(game -> filename))
	{
		perror("Error");
		free_game(game);
		return (-1);
	}
	return (0);
}

int	init_game(t_game *game, char **args)
{
	init_game_att(game, args[1]);
	game -> mlx = mlx_init();
	if (!(game -> mlx))
	{
		perror("Error");
		free_game(game);
		return (-1);
	}
	game -> screen = mlx_new_window(game -> mlx, game -> screen_x,
			game -> screen_y, game -> name);
	if (game -> screen == NULL)
	{
		perror("Error");
		free_game(game);
		return (-1);
	}
	init_images(game);
	mlx_hook(game -> screen, 17, 0, close_window, game);
	draw_ground(game);
	mlx_loop(game -> mlx);
	return (0);
}

int	main(int arg_number, char **args)
{
	t_game	*game;
	int		is_correct;

	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	is_correct = 0;
	if (arg_number != 2)
	{
		perror("Invalid number of argument");
		return (-1);
	}
	is_correct = init_game(game, args);
	if (is_correct == 0)
		free_game(game);
	return (0);
}
