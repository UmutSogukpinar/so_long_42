/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:56:16 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/30 18:42:10 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "so_long.h"
#include "check.h"
#include "map.h"

void	game_check(t_game *game)
{
	null_check(game);
	game_check_utils_one(game);
	game_check_utils_two(game);
}

void	null_check(t_game *game)
{
	if (!(game -> map) || !(game -> filename) || !(game -> name))
	{
		ft_printf("Null Check Function works. Game shuts down\n");
		close_window(game);
	}
	if (!(game -> ground_img) || !(game -> wall_img) || !(game -> collect_img))
	{
		ft_printf("Null Check Function works. Game shuts down\n");
		close_window(game);
	}
	if (!(game -> exit_img) || !(game -> mlx) || !(game -> screen))
	{
		ft_printf("Null Check Function works. Game shuts down\n");
		close_window(game);
	}
	if (!(game -> player))
	{
		ft_printf("Null Check Function works. Game shuts down\n");
		close_window(game);
	}
	if (!(game -> player -> img))
	{
		ft_printf("Null Check Function works. Game shuts down\n");
		close_window(game);
	}
}

void	game_check_utils_one(t_game *game)
{
	if (get_total_player(game) != 1)
	{
		ft_printf("Only can be one player! Game shuts down.\n");
		close_window(game);
	}
	if (get_total_exit(game) != 1)
	{
		ft_printf("Only can be one exit! Game shuts down.\n");
		close_window(game);
	}
	if (get_total_collectible(game) <= 0)
	{
		ft_printf("Collectibles supposed to be bigger than zero.\n");
		close_window(game);
	}
	if ((is_map_rectangular(game)) != 0)
	{
		ft_printf("The map is not rectangular. Game shuts down\n");
		close_window(game);
	}
	if (check_map_sides(game) != 0)
	{
		ft_printf("The map is not covered by walls. Game shuts down\n");
		close_window(game);
	}
}

void	game_check_utils_two(t_game *game)
{
	if (check_invalid_elements(game) != 0)
	{
		ft_printf("The map contains invalid chars. Game shuts down\n");
		close_window(game);
	}
	if (accessability_check(game) != 0)
	{
		ft_printf("Accessability cannot be provided. Game shuts down\n");
		close_window(game);
	}
}
