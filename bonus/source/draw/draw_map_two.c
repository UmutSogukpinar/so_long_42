/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:39:43 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/30 19:43:02 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"
#include "draw.h"

void	draw_enemy(t_game *game)
{
	int	i;
	int	j;

	if (!(game) || !(game -> map) || !(game -> mlx) || !(game -> enemy_img))
	{
		ft_printf("Error: Invalid game structure or parameters\n");
		close_window(game);
	}
	j = 0;
	while ((game->map)[j] != NULL)
	{
		i = 0;
		while ((game -> map)[j][i] != '\0')
		{
			if ((game -> map)[j][i] == 'X')
				mlx_put_image_to_window(game -> mlx, game -> screen,
					game -> enemy_img, i * CELL_LEN, j * CELL_LEN);
			i++;
		}
		j++;
	}
}
