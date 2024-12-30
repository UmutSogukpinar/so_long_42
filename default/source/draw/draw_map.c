/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:56:52 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/30 18:42:30 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"
#include "draw.h"

void	draw_ground(t_game *game)
{
	int	i;
	int	j;

	if (!(game) || !(game -> map) || !(game -> mlx) || !(game -> ground_img))
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

	if (!(game) || !(game -> map)
		|| !(game -> mlx) || !(game -> player -> img))
	{
		ft_printf("Error: Invalid game structure or parameters\n");
		close_window(game);
	}
	j = -1;
	while ((game -> map)[++j] != NULL)
	{
		i = -1;
		while ((game -> map)[j][++i] != '\0')
		{
			if ((game -> map)[j][i] == 'P')
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
		ft_printf("Error: Invalid game structure or parameters\n");
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

void	draw_collectible(t_game *game)
{
	int	i;
	int	j;

	if (!(game) || !(game -> map) || !(game -> mlx) || !(game -> collect_img))
	{
		ft_printf("Error: Invalid game structure or parameters\n");
		close_window(game);
	}
	j = 0;
	while ((game -> map)[j] != NULL)
	{
		i = 0;
		while ((game -> map)[j][i] != '\0')
		{
			if ((game -> map)[j][i] == 'C')
				mlx_put_image_to_window(game -> mlx, game -> screen,
					game -> collect_img, i * CELL_LEN, j * CELL_LEN);
			i++;
		}
		j++;
	}
}

void	draw_exit(t_game *game)
{
	int	i;
	int	j;

	if (!(game) || !(game -> map) || !(game -> mlx) || !(game -> exit_img))
	{
		ft_printf("Error: Invalid game structure or parameters\n");
		close_window(game);
	}
	j = 0;
	while ((game -> map)[j] != NULL)
	{
		i = 0;
		while ((game -> map)[j][i] != '\0')
		{
			if ((game -> map)[j][i] == 'E')
				mlx_put_image_to_window(game -> mlx, game -> screen,
					game -> exit_img, i * CELL_LEN, j * CELL_LEN);
			i++;
		}
		j++;
	}
}
