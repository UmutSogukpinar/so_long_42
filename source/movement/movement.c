/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:30:29 by umut              #+#    #+#             */
/*   Updated: 2024/12/28 22:55:50 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "movement.h"
#include "mlx.h"

void	forward_movement(t_game *game)
{
	char	target;
	char	current;

	target = (game -> map)[(game -> player -> y) - 1][game -> player -> x];
	current = (game -> map)[game -> player -> y][game -> player -> x];
	if (is_wall(target))
		return ;
	(game -> map)[(game -> player -> y) - 1][game -> player -> x] = current;
	(game -> map)[game -> player -> y][game -> player -> x] = target;
	game -> player -> y -= 1;
	draw_images(game);
}

void	backward_movement(t_game *game)
{
	char	target;
	char	current;

	target = (game -> map)[(game -> player -> y) + 1][game -> player -> x];
	current = (game -> map)[game -> player -> y][game -> player -> x];
	if (is_wall(target))
		return ;
	(game -> map)[(game -> player -> y) + 1][game -> player -> x] = current;
	(game -> map)[game -> player -> y][game -> player -> x] = target;
	game -> player -> y -= 1;
	draw_images(game);
}