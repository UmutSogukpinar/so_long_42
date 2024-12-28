/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 22:01:22 by umut              #+#    #+#             */
/*   Updated: 2024/12/27 17:09:53 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"
#include "stdio.h"

void	free_game(t_game *game)
{
	if (game == NULL)
		return ;
	free_game_sub_one(game);
	free_game_sub_two(game);
	free_game_sub_three(game);
}

void	free_game_sub_one(t_game *game)
{
	int	i;

	i = 0;
	if (game -> filename)
	{
		free(game->filename);
		game -> filename = NULL;
	}
	if (game -> name)
	{
		free(game->name);
		game -> name = NULL;
	}
	if (game -> map != NULL)
	{
		while ((game->map)[i] != NULL)
		{
			free((game->map)[i]);
			(game -> map)[i] = NULL;
			i++;
		}
		free(game->map);
		game -> map = NULL;
	}
}

void	free_game_sub_two(t_game *game)
{
	if (game -> ground_img)
		mlx_destroy_image(game -> mlx, game -> ground_img);
	if (game -> player -> img)
		mlx_destroy_image(game -> mlx, game -> player -> img);
	if (game -> wall_img)
		mlx_destroy_image(game -> mlx, game -> wall_img);
}

void	free_game_sub_three(t_game *game)
{
	if (game -> screen)
	{
		mlx_destroy_window(game -> mlx, game -> screen);
	}
	if (game -> mlx)
	{
		mlx_destroy_display(game -> mlx);
		free(game -> mlx);
	}
}