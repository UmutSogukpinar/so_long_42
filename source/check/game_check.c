/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 02:14:19 by umut              #+#    #+#             */
/*   Updated: 2024/12/29 02:26:28 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "check.h"
#include "map.h"
#include "ft_printf.h"

void	game_check(t_game *game)
{
	game_check_utils_one(game);
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
}