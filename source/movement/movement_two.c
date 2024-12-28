/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 00:48:23 by umut              #+#    #+#             */
/*   Updated: 2024/12/29 01:30:58 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "movement.h"
#include "mlx.h"
#include "ft_printf.h"

void	forward_movement_two(t_game *game, char target, char current)
{
	if (is_collectible(target))
	{
		(game -> map)[(game -> player -> y) - 1][game -> player -> x] = current;
		(game -> map)[game -> player -> y][game -> player -> x] = '0';
		(game -> player -> y) -= 1;
		(game -> gathered_collectible) += 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
}

void	backward_movement_two(t_game *game, char target, char current)
{
	if (is_collectible(target))
	{
		(game -> map)[(game -> player -> y) + 1][game -> player -> x] = current;
		(game -> map)[game -> player -> y][game -> player -> x] = '0';
		(game -> player -> y) += 1;
		(game -> gathered_collectible) += 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
}

void	right_movement_two(t_game *game, char target, char current)
{
	if (is_collectible(target))
	{
		(game -> map)[(game -> player -> y)][(game -> player -> x) + 1] = current;
		(game -> map)[game -> player -> y][game -> player -> x] = '0';
		(game -> player -> x) += 1;
		(game -> gathered_collectible) += 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
}

void	left_movement_two(t_game *game, char target, char current)
{
	if (is_collectible(target))
	{
		(game -> map)[(game -> player -> y)][(game -> player -> x) - 1] = current;
		(game -> map)[game -> player -> y][game -> player -> x] = '0';
		(game -> player -> x) -= 1;
		(game -> gathered_collectible) += 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
}
