/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:58:48 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/30 18:43:02 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_printf.h"
#include "map.h"
#include "movement.h"
#include "check.h"

void	game_winning_message(void);

void	forward_movement_two(t_game *game, char target, char current)
{
	int	y;
	int	x;

	y = game -> player -> y;
	x = game -> player -> x;
	if (is_collectible(target))
	{
		(game -> map)[y - 1][x] = current;
		(game -> map)[y][x] = '0';
		(game -> player -> y) -= 1;
		(game -> gathered_collectible) += 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
	else if (is_exit(target) && all_collectibles_gathered(game))
	{
		(game -> map)[y - 1][x] = current;
		(game -> map)[y][x] = '0';
		(game -> player -> y) -= 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		game_winning_message();
		close_window(game);
	}
}

void	backward_movement_two(t_game *game, char target, char current)
{
	int	y;
	int	x;

	y = game -> player -> y;
	x = game -> player -> x;
	if (is_collectible(target))
	{
		(game -> map)[y + 1][x] = current;
		(game -> map)[y][x] = '0';
		(game -> player -> y) += 1;
		(game -> gathered_collectible) += 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
	else if (is_exit(target) && all_collectibles_gathered(game))
	{
		(game -> map)[y + 1][x] = current;
		(game -> map)[y][x] = '0';
		(game -> player -> y) += 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		game_winning_message();
		close_window(game);
	}
}

void	right_movement_two(t_game *game, char target, char current)
{
	int	y;
	int	x;

	y = game -> player -> y;
	x = game -> player -> x;
	if (is_collectible(target))
	{
		(game -> map)[y][x + 1] = current;
		(game -> map)[y][x] = '0';
		(game -> player -> x) += 1;
		(game -> gathered_collectible) += 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
	else if (is_exit(target) && all_collectibles_gathered(game))
	{
		(game -> map)[y][x + 1] = current;
		(game -> map)[y][x] = '0';
		(game -> player -> x) += 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		game_winning_message();
		close_window(game);
	}
}

void	left_movement_two(t_game *game, char target, char current)
{
	int	y;
	int	x;

	y = game -> player -> y;
	x = game -> player -> x;
	if (is_collectible(target))
	{
		(game -> map)[y][x - 1] = current;
		(game -> map)[y][x] = '0';
		(game -> player -> x) -= 1;
		(game -> gathered_collectible) += 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
	else if (is_exit(target) && all_collectibles_gathered(game))
	{
		(game -> map)[y][x - 1] = current;
		(game -> map)[y][x] = '0';
		(game -> player -> x) -= 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		game_winning_message();
		close_window(game);
	}
}

void	game_winning_message(void)
{
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
