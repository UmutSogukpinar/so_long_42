/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:57:15 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/30 19:37:36 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "mlx.h"
#include "libft.h"
#include "draw.h"

void	init_collectible(t_game *game)
{
	int		width;
	int		height;
	char	*xpm_path;

	xpm_path = ft_strdup("./images/collectible.xpm");
	if (!game || !game->mlx)
	{
		ft_printf("Error: Invalid mlx context\n");
		free(xpm_path);
		close_window(game);
	}
	game -> collect_img = mlx_xpm_file_to_image
		(game->mlx, xpm_path, &width, &height);
	if (!(game-> collect_img))
	{
		ft_printf("Error: Failed to load XPM image\n");
		free(xpm_path);
		close_window(game);
	}
	free(xpm_path);
}

void	init_exit(t_game *game)
{
	int		width;
	int		height;
	char	*xpm_path;

	xpm_path = ft_strdup("./images/exit.xpm");
	if (!game || !game->mlx)
	{
		ft_printf("Error: Invalid mlx context\n");
		free(xpm_path);
		close_window(game);
	}
	game -> exit_img = mlx_xpm_file_to_image
		(game->mlx, xpm_path, &width, &height);
	if (!(game -> exit_img))
	{
		ft_printf("Error: Failed to load XPM image\n");
		free(xpm_path);
		close_window(game);
	}
	free(xpm_path);
}
