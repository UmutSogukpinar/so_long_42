/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 23:27:22 by umut              #+#    #+#             */
/*   Updated: 2024/12/29 01:25:53 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"
#include "mlx.h"
#include "draw.h"
#include "stdio.h"

void	init_game(t_game *game, char **args)
{
	init_game_att_one(game, args[1]);
	init_game_att_two(game);
	draw_images(game);
}

void	init_game_att_one(t_game *game, char *arg)
{
	game -> filename = ft_strdup(arg);
	game -> gathered_collectible = 0;
	game -> screen_y = (count_lines(game -> filename) * CELL_LEN);
	game -> screen_x = (count_columns(game -> filename) * CELL_LEN);
	game -> name = ft_strdup("so_long");
	if (game -> screen_x < 0 || game -> screen_y < 0 || !(game -> name) || !(game -> filename))
	{
		perror("initializing game attributes cannot be done");
		close_window(game);
	}
	init_map(game);
	game -> total_collectible = get_total_collectible(game);
	game -> moves = 0;
	game -> player -> x = get_player_x_axis(game);
	game -> player -> y = get_player_y_axis(game);
}

void	init_game_att_two(t_game *game)
{
	game -> mlx = mlx_init();
	if (!(game -> mlx))
	{
		perror("mlx attribute is null");
		close_window(game);
	}
	game -> screen = mlx_new_window(game -> mlx, game -> screen_x,
			game -> screen_y, game -> name);
	if (game -> screen == NULL)
	{
		perror("Game screen is null");
		close_window(game);
	}
	init_images(game);
	mlx_hook(game -> screen, 17, 0, close_window, game);
}

void	draw_images(t_game *game)
{
	draw_ground(game);
	draw_fox(game);
	draw_wall(game);
	draw_collectible(game);
}