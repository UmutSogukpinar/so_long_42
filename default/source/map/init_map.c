#include "unistd.h"
#include "fcntl.h"
#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"
#include "map.h"

int	init_map(t_game *game)
{
	char	**map_structure;
	int		line_count;

	line_count = count_lines(game -> filename);
	if (!(game) || !(game->filename) || line_count < 0)
	{
		ft_printf("Error at initializing map attribute\n");
		return (-1);
	}
	map_structure = malloc(sizeof(char *) * (line_count + 1));
	if (!map_structure)
		return (-1);
	if (generate_map_struct(game->filename, map_structure) < 0
		|| !map_structure)
	{
		free(map_structure);
		ft_printf("Error on init_map function\n");
		return (-1);
	}
	game->map = map_structure;
	return (0);
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
		ft_printf("Error on count_lines function\n");
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
		ft_printf("Error on count_columns function\n");
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
	char	*newline_ref;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		newline_ref = ft_strrchr(line, '\n');
		if (newline_ref)
			newline_ref[0] = '\0';
		map_struct[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map_struct[i] = NULL;
	close(fd);
	return (0);
}
