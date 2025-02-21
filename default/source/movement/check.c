#include "map.h"

int	is_wall(char c)
{
	if (c == '1')
		return (1);
	else
		return (0);
}

int	is_ground(char c)
{
	if (c == '0')
		return (1);
	else
		return (0);
}

int	is_collectible(char c)
{
	if (c == 'C')
		return (1);
	else
		return (0);
}

int	is_exit(char c)
{
	if (c == 'E')
		return (1);
	else
		return (0);
}

int	is_enemy(char c)
{
	if (c == 'X')
		return (1);
	else
		return (0);
}
