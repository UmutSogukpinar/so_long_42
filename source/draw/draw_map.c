/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:49:31 by umut              #+#    #+#             */
/*   Updated: 2024/12/28 11:33:54 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "libft.h"
#include "draw.h"
#include "mlx.h"

void	draw_ground(t_game *game)
{
	int	i;
	int	j;

	if (!(game) || !(game -> map) || !(game -> mlx) || !(game -> ground_img))
	{
		perror("Error: Invalid game structure or parameters");
		close_window(game);
	}
	j = 0;
	while ((game->map)[j] != NULL)
	{
		i = 0;
		while ((game -> map)[j][i] != '\0')
		{
			if ((game -> map)[j][i] == '0')
				mlx_put_image_to_window(game -> mlx, game -> screen,
					game -> ground_img, i * CELL_LEN, j * CELL_LEN);
			i++;
		}
		j++;
	}
}

void	draw_fox(t_game *game)
{
	int		i;
	int		j;

	if (!(game) || !(game -> map) || 
		!(game -> mlx) || !(game -> player -> img))
	{
		perror("Error: Invalid game structure or parameters");
		close_window(game);
	}
	j = -1;
	while ((game -> map)[++j] != NULL)
	{
		i = -1;
		while ((game -> map)[j][++i] != '\0')
		{
			if ((game -> map)[j][i] == 'e')
			{
				mlx_put_image_to_window(game -> mlx, game -> screen,
					game -> player -> img, i * CELL_LEN, j * CELL_LEN);
				game -> player -> x = i;
				game -> player -> y = j;
			}
		}
	}
}

void	draw_wall(t_game *game)
{
	int	i;
	int	j;

	if (!(game) || !(game -> map) || !(game -> mlx) || !(game -> wall_img))
	{
		perror("Error: Invalid game structure or parameters");
		close_window(game);
	}
	j = 0;
	while ((game -> map)[j] != NULL)
	{
		i = 0;
		while ((game -> map)[j][i] != '\0')
		{
			if ((game -> map)[j][i] == '1')
				mlx_put_image_to_window(game -> mlx, game -> screen,
					game -> wall_img, i * CELL_LEN, j * CELL_LEN);
			i++;
		}
		j++;
	}
}