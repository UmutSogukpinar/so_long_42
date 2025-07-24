#include "../../includes/game.h"

static bool	is_line_empty(const char *line);
static bool	read_map_lines(t_game *game, int fd);
static bool	append_line_to_map(t_game *game, char *line);
static char	**realloc_matrix(char **matrix, size_t size, char *line);

bool	init_map(t_game *game)
{
	int	fd;

	fd = open(game->map.path, O_RDONLY);
	if (fd < 0)
		return (display_error_msg(FD_OPEN_ERR, true));
	if (!read_map_lines(game, fd))
	{
		clear_get_next_line(fd);
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

static bool	read_map_lines(t_game *game, int fd)
{
	char	*line;
	bool	seen_blank;

	seen_blank = false;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_line_empty(line))
			seen_blank = true;
		else
		{
			if (seen_blank)
			{
				free(line);
				return (display_error_msg(INV_MAP, false));
			}
			if (!append_line_to_map(game, line))
				return (false);
			continue ;
		}
		free(line);
	}
	return (true);
}

static bool	append_line_to_map(t_game *game, char *line)
{
	char	*trimmed;

	ft_rtrim(line);
	trimmed = ft_strdup(line);
	free(line);
	if (!trimmed)
		return (display_error_msg(INIT_ERR, true));
	if (game->map.width == 0)
		game->map.width = ft_strlen(trimmed);
	else
		if (game->map.width != ft_strlen(trimmed))
		{
			free(trimmed);
			return (display_error_msg(MAP_NOT_RECT, false));
		}
	game->map.matrix = realloc_matrix(game->map.matrix, game->map.height, trimmed);
	game->map.height++;
	if (!game->map.matrix)
		return (false);
	return (true);
}

static char	**realloc_matrix(char **matrix, size_t size, char *line)
{
	char	**new_matrix;
	size_t	i;

	new_matrix = ft_calloc(size + 2, sizeof(char *));
	if (!new_matrix)
	{
		free(line);
		display_error_msg(INIT_ERR, true);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		new_matrix[i] = matrix[i];
		i++;
	}
	new_matrix[i] = line;
	new_matrix[i + 1] = NULL;
	free(matrix);
	return (new_matrix);
}

static bool	is_line_empty(const char *line)
{
	int	i;

	if (!line)
		return (false);
	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]))
			return (false);
		i++;
	}
	return (true);
}
