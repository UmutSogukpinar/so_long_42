/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:58:54 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/01 00:20:12 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_printf.h"
#include "map.h"
#include "movement.h"
#include "check.h"

void	game_winning_message(t_game *game);

void	movement(t_game *game, int t_x, int t_y)
{
	char	target_cell;
	int		x;
	int		y;

	x = game -> player -> x;
	y = game -> player -> y;
	target_cell = (game -> map)[y + t_y][x + t_x];
	if (is_ground(target_cell))
		movement_utils(game, t_x, t_y);
	else if (is_wall(target_cell))
		return ;
	else if (is_collectible(target_cell))
	{
		movement_utils(game, t_x, t_y);
		(game -> gathered_collectible) += 1;
	}
	else if (is_exit(target_cell) && all_collectibles_gathered(game))
	{
		(game -> moves) += 1;
		game_winning_message(game);
		close_window(game);
	}
}

void	movement_utils(t_game *game, int t_x, int t_y)
{
	int		y;
	int		x;
	char	current_cell;

	y = game -> player -> y;
	x = game -> player -> x;
	current_cell = (game -> map)[y][x];
	(game -> map)[y + t_y][x + t_x] = current_cell;
	(game -> map)[y][x] = '0';
	(game -> player -> y) += t_y;
	(game -> player -> x) += t_x;
	(game -> moves) += 1;
	ft_printf("Number of movements: %d\n", (game -> moves));
	draw_images(game);
}

void	game_winning_message(t_game *game)
{
	ft_printf("Number of movements: %d\n", (game -> moves));
	ft_printf("⣿⣿⣿⣿⣿⣿⣿⣿⠿⠟⠛⠛⠛⠛⠛⠿⢿⣿⣿⣿⣿⣿⣿⣿\n"
		"⣿⣿⣿⣿⡿⠟⣉⣴⣾⣿⣿⣿⣿⣿⣿⣶⣦⣉⠛⢿⣿⣿⣿⣿\n"
		"⣿⣿⣿⠟⣡⠚⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠓⣄⠻⣿⣿⣿\n"
		"⣿⣿⠃⣴⡿⠲⠤⠈⠙⢿⣿⣿⣿⣿⡿⠋⠁⠤⠖⢿⣦⠘⣿⣿\n"
		"⣿⡏⣸⣿⡷⠶⠒⠀⣀⣠⣿⣿⣿⣿⣄⡀⠀ ⠒⠶⢾⣿⡇⢹\n"
		"⣿⠁⣿⣿⣦⣤⣶⣿⡏⠹⠿⠋⠙⠿⠟⢉⣿⣶⣤⣴⣿⣿⠈⣿\n"
		"⣿⠀⣿⣿⣿⣿⣿⡿⠿⠦⣤⣴⣶⣤⠴⠿⢿⣿⣿⣿⣿⣿⠀⣿\n"
		"⣿⡆⢻⠿⢿⠛⣠⣶⣶⣶⣦⡈⢁⣤⣶⣶⣦⣄⠙⡿⠿⠏⢰⣿\n"
		"⣿⡇⢠⣴⣦⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⣴⣦⡄⢸⣿\n"
		"⣿⡇⢻⣿⣿⡄⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢠⣿⣿⡏⢸⣿\n"
		"⣿⣧⡈⠻⠟⠃⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠘⠛⠛⢁⣼⣿\n"
		"⣿⣿⣿⣶⣶⣾⣶⣄⡙⠻⣿⣿⣿⣿⠟⠋⣠⣶⣷⣶⣶⣿⣿⣿\n"
		"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣄⡉⢁⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
	ft_printf("Congratz Champ!!! YOU WON.\n");
}
