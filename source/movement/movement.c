/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:30:29 by umut              #+#    #+#             */
/*   Updated: 2024/12/29 00:17:33 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "movement.h"
#include "mlx.h"
#include "ft_printf.h"

void	forward_movement(t_game *game)
{
	char	target;
	char	current;

	target = (game -> map)[(game -> player -> y) - 1][game -> player -> x];
	current = (game -> map)[game -> player -> y][game -> player -> x];
	if (is_wall(target))
		return ;
	if (is_ground(target))
	{
		(game -> map)[(game -> player -> y) - 1][game -> player -> x] = current;
		(game -> map)[game -> player -> y][game -> player -> x] = target;
		(game -> player -> y) -= 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
}

void	backward_movement(t_game *game)
{
	char	target;
	char	current;

	target = (game -> map)[(game -> player -> y) + 1][game -> player -> x];
	current = (game -> map)[game -> player -> y][game -> player -> x];
	if (is_wall(target))
		return ;
	if (is_ground(target))
	{
		(game -> map)[(game -> player -> y) + 1][game -> player -> x] = current;
		(game -> map)[game -> player -> y][game -> player -> x] = target;
		(game -> player -> y) += 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
}

void	right_movement(t_game *game)
{
	char	target;
	char	current;

	target = (game -> map)[(game -> player -> y)][(game -> player -> x) + 1];
	current = (game -> map)[game -> player -> y][game -> player -> x];
	if (is_wall(target))
		return ;
	if (is_ground(target))
	{
		(game -> map)[(game -> player -> y)][(game -> player -> x) + 1] = current;
		(game -> map)[game -> player -> y][game -> player -> x] = target;
		(game -> player -> x) += 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
}

void	left_movement(t_game *game)
{
	char	target;
	char	current;

	target = (game -> map)[(game -> player -> y)][(game -> player -> x) - 1];
	current = (game -> map)[game -> player -> y][game -> player -> x];
	if (is_wall(target))
		return ;
	if (is_ground(target))
	{
		(game -> map)[(game -> player -> y)][(game -> player -> x) - 1] = current;
		(game -> map)[game -> player -> y][game -> player -> x] = target;
		(game -> player -> x) += 1;
		(game -> moves) += 1;
		ft_printf("number of movements: %d\n", (game -> moves));
		draw_images(game);
	}
}