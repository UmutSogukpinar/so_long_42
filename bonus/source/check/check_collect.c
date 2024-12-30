/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:56:09 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/30 13:56:11 by usogukpi         ###   ########.fr       */
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
