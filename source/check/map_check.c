/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 02:31:01 by umut              #+#    #+#             */
/*   Updated: 2024/12/29 12:15:54 by umut             ###   ########.fr       */
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
		if ((ft_strlen((game -> map)[i])) != (size_t) row)
			return (-1);
		i++;
	}
	return (0);
}

int	check_map_sides(t_game *game)
{
	int	i;
	int	row;
	int	column;

	row = (game -> screen_x) / CELL_LEN;
	column = (game -> screen_y) / CELL_LEN;
	i = -1;
	while (++i < row)
		if ((game -> map)[0][i] != '1')
			return (-1);
	i = -1;
	while (++i < row)
		if ((game -> map)[column - 1][i] != '1')
			return (-1);
	i = -1;
	while (++i < column)
		if ((game -> map)[i][0] != '1' || (game -> map)[i][row - 1] != '1')
			return (-1);
	return (0);
}

int	check_invalid_elements(t_game *game)
{
	char	**map;
	char	*check_str;
	char	*game_element_set;
	int		i;

	map = game -> map;
	game_element_set = ft_strdup("10PEC");
	if (!game_element_set)
		return (-1);
	i = -1;
	while (map[++i] != NULL)
	{
		check_str = ft_strtrim(map[i], game_element_set);
		if (!check_str)
		{
			free(game_element_set);
			return (-1);
		}
		if (ft_strlen(check_str) > 0)
		{
			free(game_element_set);
			free(check_str);
			return (-1);
		}
		free(check_str);
	}
	free (game_element_set);
	return (0);
}
