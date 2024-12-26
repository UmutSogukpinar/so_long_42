/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:49:31 by umut              #+#    #+#             */
/*   Updated: 2024/12/27 00:35:02 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "libft.h"
#include "draw.h"
#include "mlx.h"

int	draw_ground(t_game *game)
{
	int	i;
	int	j;

	if (!(game) || !(game -> map) || !(game -> mlx) || !(game -> ground_img))
	{
		printf("%p\n", game -> map);
		close_window(game);;
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
	return (0);
}

int	draw_fox(t_game *game)
{
	int		i;
	int		j;

	if (!(game) || !(game -> map) || !(game -> mlx) || !(game -> fox_img))
	{
		perror("Error: Invalid game structure or parameters");
		return (-1);
	}
	j = 0;
	while ((game->map)[j] != NULL)
	{
		i = 0;
		while ((game -> map)[j][i] != '\0')
		{
			if ((game -> map)[j][i] == 'e')
				mlx_put_image_to_window(game -> mlx, game -> screen,
					game -> fox_img, i * CELL_LEN, j * CELL_LEN);
			i++;
		}
		j++;
	}
	return (0);
}
