/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:30:29 by umut              #+#    #+#             */
/*   Updated: 2024/12/29 14:22:40 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "movement.h"
#include "check.h"
#include "mlx.h"
#include "ft_printf.h"

void	forward_movement(t_game *game)
{
	char	target;
	char	current;
	int		x;
	int		y;

	x = game -> player -> x;
	y = game -> player -> y;
	target = (game -> map)[y - 1][x];
	current = (game -> map)[y][x];
	if (is_ground(target))
	{
		(game -> map)[y - 1][x] = current;
		(game -> map)[y][x] = target;
		(game -> player -> y) -= 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
	else if (is_wall(target))
		return ;
	else if (is_collectible(target))
		forward_movement_two(game, target, current);
	else if (is_exit(target) && all_collectibles_gathered(game))
		right_movement_two(game, target, current);
}

void	backward_movement(t_game *game)
{
	char	target;
	char	current;
	int		x;
	int		y;

	x = game -> player -> x;
	y = game -> player -> y;
	target = (game -> map)[y + 1][x];
	current = (game -> map)[y][x];
	if (is_ground(target))
	{
		(game -> map)[y + 1][x] = current;
		(game -> map)[y][x] = target;
		(game -> player -> y) += 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
	else if (is_wall(target))
		return ;
	else if (is_collectible(target))
		backward_movement_two(game, target, current);
	else if (is_exit(target) && all_collectibles_gathered(game))
		right_movement_two(game, target, current);
}

void	right_movement(t_game *game)
{
	char	target;
	char	current;
	int		x;
	int		y;

	x = game -> player -> x;
	y = game -> player -> y;
	target = (game -> map)[y][x + 1];
	current = (game -> map)[y][x];
	if (is_ground(target))
	{
		(game -> map)[y][x + 1] = current;
		(game -> map)[y][x] = target;
		(game -> player -> x) += 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
	else if (is_wall(target))
		return ;
	else if (is_collectible(target))
		right_movement_two(game, target, current);
	else if (is_exit(target) && all_collectibles_gathered(game))
		right_movement_two(game, target, current);
}

void	left_movement(t_game *game)
{
	char	target;
	char	current;
	int		x;
	int		y;

	x = game -> player -> x;
	y = game -> player -> y;
	target = (game -> map)[y][x - 1];
	current = (game -> map)[y][x];
	if (is_ground(target))
	{
		(game -> map)[y][x - 1] = current;
		(game -> map)[y][x] = target;
		(game -> player -> x) -= 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
	else if (is_wall(target))
		return ;
	else if (is_collectible(target))
		left_movement_two(game, target, current);
	else if (is_exit(target) && all_collectibles_gathered(game))
		right_movement_two(game, target, current);
}
