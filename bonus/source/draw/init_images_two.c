/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:57:15 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/30 19:57:37 by usogukpi         ###   ########.fr       */
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
	if (!game || !(game -> mlx) || !xpm_path)
	{
		if (xpm_path)
			free(xpm_path);
		ft_printf("Error: Invalid mlx context\n");
		close_window(game);
	}
	game -> collect_img = mlx_xpm_file_to_image
		(game -> mlx, xpm_path, &width, &height);
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
	if (!game || !(game -> mlx) || !xpm_path)
	{
		if (xpm_path)
			free(xpm_path);
		ft_printf("Error: Invalid mlx context\n");
		close_window(game);
	}
	game -> exit_img = mlx_xpm_file_to_image
		(game -> mlx, xpm_path, &width, &height);
	if (!(game -> exit_img))
	{
		ft_printf("Error: Failed to load XPM image\n");
		free(xpm_path);
		close_window(game);
	}
	free(xpm_path);
}

void	init_enemy(t_game *game)
{
	int		width;
	int		height;
	char	*xpm_path;

	xpm_path = ft_strdup("./images/enemy_2.xpm");
	if (!game || !(game -> mlx) || !xpm_path)
	{
		if (xpm_path)
			free(xpm_path);
		ft_printf("Error: Invalid mlx context\n");
		close_window(game);
	}
	game -> enemy_img = mlx_xpm_file_to_image
		(game -> mlx, xpm_path, &width, &height);
	if (! (game -> enemy_img))
	{
		ft_printf("Error: Failed to load XPM image\n");
		free(xpm_path);
		close_window(game);
	}
	free(xpm_path);
}

void	draw_score(t_game *game)
{
	char	*total_move;
	int		white;

	total_move = ft_itoa(game -> moves);
	if (!total_move)
	{
		ft_printf("Error on draw_score function\n");
		close_window(game);
	}
	white = 0x00000;
	mlx_string_put(game -> mlx, game -> screen,
		(98 * (game -> screen_x)) / 100, (98 * (game -> screen_y)) / 100,
		white, total_move);
	free(total_move);
}
