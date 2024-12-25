/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:49:31 by umut              #+#    #+#             */
/*   Updated: 2024/12/26 01:31:05 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "libft.h"
#include "draw.h"
#include "mlx.h"

int	draw_ground(t_game *game)
{
	int		i;
	int		j;

	if (!(game) || !(game -> map) || !(game -> mlx) || !(game -> ground_img))
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
			if ((game -> map)[j][i] == '0')
				mlx_put_image_to_window(game -> mlx, game -> screen,
					game -> ground_img, i * CELL_LEN, j * CELL_LEN);
			i++;
		}
		j++;
	}
	return (0);
}
