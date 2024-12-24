/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:53:23 by umut              #+#    #+#             */
/*   Updated: 2024/12/24 23:17:54 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "so_long.h"
#include "mlx.h"
#include "libft.h"

int	draw_square(void *mlx, void *window, char *xpm_path, int x, int y)
{
	void	*image;
	int		width;
	int		height;

	image = mlx_xpm_file_to_image(mlx, xpm_path, &width, &height);
	if (image)
	{
		mlx_put_image_to_window(mlx, window, image, x, y);
		return (0);
	}
	else
	{
		printf("Error: Image cannot be used");
		return (-1);
	}
}

int	draw_ground(t_game *game)
{
	int		i;
	int		j;
	char	**map;
	char	*xpm_path;

	xpm_path = ft_strdup("../../images/grass.xpm");
	if (!game || !game->map || !game->mlx || !game->screen || !xpm_path)
		return (-1); 
	map = game -> map;
	i = 0;
	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == '0')
				draw_square(game -> mlx, game -> screen, xpm_path, i * CELL_LEN, j * CELL_LEN);
			i++;
		}
		j++;
	}
	free(xpm_path);
	return (0);
}
