/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessability_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:56:02 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/31 00:26:14 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"
#include "check.h"

int	accessability_check(t_game *game)
{
	char	**map_copy;
	int		rows;

	rows = count_lines(game -> filename);
	map_copy = copy_map(game, rows);
	if (!map_copy)
		return (-1);
	flood_fill(game, map_copy, game -> player -> x, game -> player -> y);
	if (scan_map(map_copy) != 0)
	{
		free_copy(map_copy);
		return (-1);
	}
	free_copy(map_copy);
	return (0);
}

void	flood_fill(t_game *game, char **map_copy, int x, int y)
{
	int	rows;
	int	cols;

	cols = count_columns(game -> filename);
	rows = count_lines(game -> filename);
	if (x < 0 || y < 0 || x >= cols || y >= rows)
		return ;
	if (map_copy[y][x] == '0' || map_copy[y][x] == 'C'
		|| map_copy[y][x] == 'P')
		map_copy[y][x] = 'F';
	else if (map_copy[y][x] == 'E')
	{
		map_copy[y][x] = 'F';
		return ;
	}
	else
		return ;
	flood_fill(game, map_copy, x + 1, y);
	flood_fill(game, map_copy, x - 1, y);
	flood_fill(game, map_copy, x, y + 1);
	flood_fill(game, map_copy, x, y - 1);
}

char	**copy_map(t_game *game, int rows)
{
	int		i;
	char	**new;

	new = malloc(sizeof(char *) * (rows + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		new[i] = ft_strdup((game -> map)[i]);
		if (!(new[i]))
		{
			while (--i <= 0)
				free(new[i]);
			free(new);
			return (NULL);
		}
		i++;
	}
	new[i] = NULL;
	return (new);
}

int	scan_map(char **map_copy)
{
	int	i;
	int	j;

	j = 0;
	while (map_copy[j] != NULL)
	{
		i = 0;
		while (map_copy[j][i] != '\0')
		{
			if (map_copy[j][i] == 'E' || map_copy[j][i] == 'C')
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

void	free_copy(char **map_copy)
{
	int	j;

	j = 0;
	while (map_copy[j] != NULL)
	{
		free(map_copy[j]);
		j++;
	}
	free(map_copy);
}
