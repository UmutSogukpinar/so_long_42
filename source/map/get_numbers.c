/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 00:27:44 by umut              #+#    #+#             */
/*   Updated: 2024/12/29 00:33:18 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "stddef.h"

int	get_total_collectible(t_game *game)
{
	int	i;
	int	j;
	int	acc;

	j = 0;
	acc = 0;
	while ((game -> map)[j] != NULL)
	{
		i = 0;
		while ((game -> map)[j][i] != '\0')
		{
			if ((game -> map)[j][i] == 'C')
				acc += 1;
			i++;
		}
		j++;
	}
	return (acc);
}
