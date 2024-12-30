/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:58:54 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/31 01:40:30 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_printf.h"
#include "map.h"
#include "movement.h"
#include "check.h"

void	game_winning_message(void);
void	game_lose_message(void);

void	movement(t_game *game, int t_x, int t_y)
{
	char	target_cell;
	char	current_cell;
	int		x;
	int		y;

	x = game -> player -> x;
	y = game -> player -> y;
	target_cell = (game -> map)[y + t_y][x + t_x];
	current_cell = (game -> map)[y][x];
	if (is_ground(target_cell))
	{
		(game -> map)[y + t_y][x + t_x] = current_cell;
		(game -> map)[y][x] = target_cell;
		(game -> player -> y) += t_y;
		(game -> player -> x) += t_x;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
	else if (is_wall(target_cell))
		return ;
	movement_two(game, target_cell, current_cell, t_x, t_y);
	move_three(game, target_cell, current_cell, t_x, t_y);
}

void	movement_two(t_game *game, char t_cell, char c_cell, int t_x, int t_y)
{
	int	y;
	int	x;

	y = game -> player -> y;
	x = game -> player -> x;
	if (is_collectible(t_cell))
	{
		(game -> map)[y + t_y][x + t_x] = c_cell;
		(game -> map)[y][x] = '0';
		(game -> player -> y) += t_y;
		(game -> player -> x) += t_x;
		(game -> gathered_collectible) += 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
	else if (is_exit(t_cell) && all_collectibles_gathered(game))
	{
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		game_winning_message();
		close_window(game);
	}
}

void	move_three(t_game *game, char t_cell, char c_cell, int t_x, int t_y)
{
	int	y;
	int	x;

	y = game -> player -> y;
	x = game -> player -> x;
	if (is_enemy(t_cell))
	{
		(game -> map)[y + t_y][x + t_x] = c_cell;
		(game -> map)[y][x] = '0';
		(game -> player -> y) += t_y;
		(game -> player -> x) += t_x;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		game_lose_message();
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
void	game_lose_message(void)
{
	ft_printf("⠟⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠛⢻⣿\n"
			"⡆⠊⠈⣿⢿⡟⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣎⠈⠻\n"
			"⣷⣠⠁⢀⠰⠀⣰⣿⣿⣿⣿⣿⣿⠟⠋⠛⠛⠿⠿⢿⣿⣿⣿⣧⠀⢹⣿⡑⠐⢰\n"
			"⣿⣿⠀⠁⠀⠀⣿⣿⣿⣿⠟⡩⠐⠀⠀⠀⠀⢐⠠⠈⠊⣿⣿⣿⡇⠘⠁⢀⠆⢀\n"
			"⣿⣿⣆⠀⠀⢤⣿⣿⡿⠃⠈⠀⣠⣶⣿⣿⣷⣦⡀⠀⠀⠈⢿⣿⣇⡆⠀⠀⣠⣾\n"
			"⣿⣿⣿⣧⣦⣿⣿⣿⡏⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⡆⠀⠀⠐⣿⣿⣷⣦⣷⣿⣿\n"
			"⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⣿⣿⣿⣿⣿⣿⣿\n"
			"⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⣾⣿⣿⠋⠁⠀⠉⠻⣿⣿⣧⠀⠠⣿⣿⣿⣿⣿⣿⣿\n"
			"⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⣿⡿⠁⠀⠀⠀⠀⠀⠘⢿⣿⠀⣺⣿⣿⣿⣿⣿⣿⣿\n"
			"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣠⣂⠀⠀⠀⠀⠀⠀⠀⢀⣁⢠⣿⣿⣿⣿⣿⣿⣿⣿\n"
			"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣄⣤⣤⣔⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
	ft_printf("Game Over! Better luck next time.\n");
}

