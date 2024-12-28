/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:49:05 by umut              #+#    #+#             */
/*   Updated: 2024/12/29 00:46:47 by umut             ###   ########.fr       */
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
