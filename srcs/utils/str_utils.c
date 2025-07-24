#include "../../includes/game.h"

bool	is_space(char c)
{
	int	i;

	i = 0;
	while (SPACE_SET[i])
	{
		if (SPACE_SET[i] == c)
			return (true);
		i++;
	}
	return (false);
}

void	ft_rtrim(char *str)
{
	int	end;

	if (!str)
		return ;
	end = ft_strlen(str) - 1;
	while (end >= 0 && is_space(str[end]))
		end--;
	str[end + 1] = '\0';
}

char	**copy_matrix(t_game *game, char **matrix)
{
	char	**copy;
	int		i;

	copy = ft_calloc((game->map.height) + 1, sizeof(char *));
	if (!copy)
	{
		display_error_msg(INIT_ERR, true);
		return (NULL);
	}
	i = 0;
	while (matrix[i])
	{
		copy[i] = ft_strdup(matrix[i]);
		if (!copy[i])
		{
			display_error_msg(INIT_ERR, true);
			free_tab(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

bool	is_map_element(char c)
{
	int		i;
	char	*map_set;

	i = 0;
	map_set = MAP_SET;
	while (map_set[i])
	{
		if (map_set[i] == c)
			return (true);
		i++;
	}
	return (false);
}
