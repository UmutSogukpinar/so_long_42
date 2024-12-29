/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 02:14:19 by umut              #+#    #+#             */
/*   Updated: 2024/12/29 03:06:22 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "check.h"
#include "map.h"
#include "ft_printf.h"

void	game_check(t_game *game)
{
	null_check(game);
	game_check_utils_one(game);
}

void	null_check(t_game *game)
{
	if(!(game -> map) || !(game -> filename) || !(game -> name))
	{
		ft_printf("Null Check Function works. Game shuts down");
		close_window(game);
	}
	if(!(game -> ground_img) || !(game -> wall_img) || !(game -> collect_img))
	{
		ft_printf("Null Check Function works. Game shuts down");
		close_window(game);
	}
	if(!(game -> exit_img) || !(game -> mlx) || !(game -> screen))
	{
		ft_printf("Null Check Function works. Game shuts down");
		close_window(game);
	}
	if(!(game -> player))
	{
		ft_printf("Null Check Function works. Game shuts down");
		close_window(game);
	}
	if (!(game -> player -> img))
	{
		ft_printf("Null Check Function works. Game shuts down");
		close_window(game);
	}
}

void	game_check_utils_one(t_game *game)
{
	if (get_total_player(game) != 1)
	{
		ft_printf("Only can be one player! Game shuts down.");
		close_window(game);
	}
	if (get_total_exit(game) != 1)
	{
		ft_printf("Only can be one exit! Game shuts down.");
		close_window(game);
	}
	if (get_total_collectible(game) <= 0)
	{
		ft_printf("Collectibles supposed to be bigger than zero");
		close_window(game);
	}
	if ((is_map_rectangular(game)) == 0)
	{
		ft_printf("The map is not rectangular");
		close_window(game);
	}
}
