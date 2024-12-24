/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:18:02 by umut              #+#    #+#             */
/*   Updated: 2024/12/22 21:48:48 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "so_long.h"
#include "map.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	init_map(t_game *game)
{
	char	**map_structure;
	int		line_count;

	line_count = count_lines(game -> filename);
	if (!game || !game->filename)
    {
		printf("Error: Invalid game structure or filename.\n");
		return (-1);
	}
	if (line_count < 0)
	{
		printf("Error: Failed to count lines in the map file.\n");
		return (-1);
	}
    map_structure = malloc(sizeof(char *) * (line_count + 1));
    if (generate_map_struct(game->filename, map_structure) < 0 || !map_structure)
    {
        free(map_structure);
        printf("Error:\n");
        return (-1);
    }
    game->map = map_structure;
    return 0;
}

int	is_line(char *line)
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

int	count_lines(char *file_name)
{
	int		fd;
	int		counter;
	char	*line;

	fd = open(file_name, O_RDONLY);
    if (fd < 0)
    {
        printf("Error: Unable to open file.\n");
        return (-1);
    }
	line = get_next_line(fd);
	counter = 0;
    while (line != NULL)
    {
		counter++;
		free(line);
		line = get_next_line(fd);
    }
	close(fd);
	return (counter);
}

int	count_columns(char *file_name)
{
	int		fd;
	char	*line;
	int		column_count;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Unable to open file.\n");
		return (-1);
	}
	line = get_next_line(fd);
	column_count = 0;
	if (line)
	{
		while (line[column_count] != '\n' && line[column_count] != '\0')
			column_count++;
		free(line);
	}
	close(fd);
	return (column_count);
}

int	generate_map_struct(char *file_name, char **map_struct)
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

