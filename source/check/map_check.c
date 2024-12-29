/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 02:31:01 by umut              #+#    #+#             */
/*   Updated: 2024/12/29 03:15:01 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"
#include "ft_printf.h"

int	is_map_rectangular(t_game *game)
{
	int	i;
	int	row;

	row = (game -> screen_x) / CELL_LEN;
	i = 0;
	while (i < ((game -> screen_y) / CELL_LEN))
	{
		if ((ft_strlen((game -> map)[i]) - 1) != (size_t) row)
			return (0);
		i++;
	}
	return (1);
}
