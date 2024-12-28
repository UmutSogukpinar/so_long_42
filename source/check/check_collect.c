/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 01:56:20 by umut              #+#    #+#             */
/*   Updated: 2024/12/29 01:57:25 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	all_collectibles_gathered(t_game *game)
{
	if (game -> total_collectible == game -> gathered_collectible)
		return (1);
	else
		return (0);
}
