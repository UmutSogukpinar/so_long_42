#include "mlx.h"
#include "ft_printf.h"
#include "movement.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		ft_printf("User enter \"ESC\" button. Game shuts down\n");
		close_window(game);
	}
	else if (keycode == 119)
		movement(game, 0, -1);
	else if (keycode == 115)
		movement(game, 0, 1);
	else if (keycode == 100)
		movement(game, 1, 0);
	else if (keycode == 97)
		movement(game, -1, 0);
	return (0);
}
