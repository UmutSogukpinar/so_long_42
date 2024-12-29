/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:15:01 by umut              #+#    #+#             */
/*   Updated: 2024/12/29 14:24:29 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "unistd.h"
#include "draw.h"
#include "mlx.h"
#include "libft.h"

void	init_collectible(t_game *game)
{
	int		width;
	int		height;
	char	*xpm_path;

	xpm_path = ft_strdup("./images/collectible.xpm");
	if (!game || !game->mlx)
	{
		perror("Error: Invalid mlx context");
		free(xpm_path);
		close_window(game);
	}
	game -> collect_img = mlx_xpm_file_to_image
		(game->mlx, xpm_path, &width, &height);
	if (!(game-> collect_img))
	{
		perror("Error: Failed to load XPM image");
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
		perror("Error: Invalid mlx context");
		free(xpm_path);
		close_window(game);
	}
	game -> exit_img = mlx_xpm_file_to_image
		(game->mlx, xpm_path, &width, &height);
	if (!(game -> exit_img))
	{
		perror("Error: Failed to load XPM image");
		free(xpm_path);
		close_window(game);
	}
	free(xpm_path);
}
