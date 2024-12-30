/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:58:41 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/30 13:58:43 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	is_wall(char c)
{
	if (c == '1')
		return (1);
	else
		return (0);
}

int	is_ground(char c)
{
	if (c == '0')
		return (1);
	else
		return (0);
}

int	is_collectible(char c)
{
	if (c == 'C')
		return (1);
	else
		return (0);
}

int	is_exit(char c)
{
	if (c == 'E')
		return (1);
	else
		return (0);
}
