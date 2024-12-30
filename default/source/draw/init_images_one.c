/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:57:06 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/30 19:47:33 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "mlx.h"
#include "libft.h"
#include "draw.h"

void	init_images(t_game *game)
{
	init_ground(game);
	init_fox(game);
	init_wall(game);
	init_collectible(game);
	init_exit(game);
}

void	init_ground(t_game *game)
{
	int		width;
	int		height;
	char	*xpm_path;

	xpm_path = ft_strdup("./images/grass.xpm");
	if (!game || !game->mlx)
	{
		ft_printf("Error: Invalid mlx context\n");
		free(xpm_path);
		close_window(game);
	}
	game -> ground_img = mlx_xpm_file_to_image
		(game->mlx, xpm_path, &width, &height);
	if (!(game->ground_img))
	{
		ft_printf("Error: Failed to load XPM image\n");
		free(xpm_path);
		close_window(game);
	}
	free(xpm_path);
}

void	init_fox(t_game *game)
{
	int		width;
	int		height;
	char	*xpm_path;

	xpm_path = ft_strdup("./images/fox.xpm");
	if (!game || !game->mlx)
	{
		ft_printf("Error: Invalid mlx context\n");
		free(xpm_path);
		close_window(game);
	}
	game -> player -> img = mlx_xpm_file_to_image
		(game->mlx, xpm_path, &width, &height);
	if (!(game-> player -> img))
	{
		ft_printf("Error: Failed to load XPM image\n");
		free(xpm_path);
		close_window(game);
	}
	free(xpm_path);
}

void	init_wall(t_game *game)
{
	int		width;
	int		height;
	char	*xpm_path;

	xpm_path = ft_strdup("./images/wall.xpm");
	if (!game || !game->mlx)
	{
		ft_printf("Error: Invalid mlx context\n");
		free(xpm_path);
		close_window(game);
	}
	game -> wall_img = mlx_xpm_file_to_image
		(game->mlx, xpm_path, &width, &height);
	if (!(game -> wall_img))
	{
		ft_printf("Error: Failed to load XPM image\n");
		free(xpm_path);
		close_window(game);
	}
	free(xpm_path);
}
