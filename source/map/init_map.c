/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:18:02 by umut              #+#    #+#             */
/*   Updated: 2024/12/21 18:51:27 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "get_next_line.h"
#include "push_swap.h"
#include <fcntl.h>
#include <unistd.h>

static	int	is_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	count_lines(char *file_name)
{
	int		fd;
	int		counter;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0 )
		return (-1);
	counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (is_line(line))
			counter++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (counter);
}

static int	generate_map_struct(char *file_name, char **map_struct)
{
	int		i;
	int		fd;
	char	*line;	

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map_struct[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map_struct[i] = NULL;
	close(fd);
	return (0);
}

int	init_map(t_game *game, char *arg)
{
	char	**map_struc;
	int		line_count;

	line_count = count_lines(game -> filename);
	map_struc = malloc(sizeof(char *) * (line_count + 1));
	if (!map_struc)
		return (-1);
	generate_map_struct(game -> filename, map_struc);
	
}
