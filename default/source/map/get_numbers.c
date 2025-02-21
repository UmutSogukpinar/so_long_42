#include "stddef.h"
#include "map.h"

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

int	get_total_player(t_game *game)
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
			if ((game -> map)[j][i] == 'P')
				acc += 1;
			i++;
		}
		j++;
	}
	return (acc);
}

int	get_total_exit(t_game *game)
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
			if ((game -> map)[j][i] == 'E')
				acc += 1;
			i++;
		}
		j++;
	}
	return (acc);
}

int	get_player_x_axis(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while ((game -> map)[j] != NULL)
	{
		i = 0;
		while ((game -> map)[j][i] != '\0')
		{
			if ((game -> map)[j][i] == 'C')
				return (i);
			i++;
		}
		j++;
	}
	return (-1);
}

int	get_player_y_axis(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while ((game -> map)[j] != NULL)
	{
		i = 0;
		while ((game -> map)[j][i] != '\0')
		{
			if ((game -> map)[j][i] == 'C')
				return (j);
			i++;
		}
		j++;
	}
	return (-1);
}
