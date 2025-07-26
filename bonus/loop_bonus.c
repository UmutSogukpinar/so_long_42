#include "../includes/game.h"
#include "../includes/game_bonus.h"

static int handle_keypress(int keycode, t_game *game);
static int render_frame(t_game *game);

bool    execute_game(t_game *game)
{
    void *win = game->mlx->win;

    mlx_hook(win, 17, 0, handle_close, game);

    mlx_hook(win, 2, 1L << 0, handle_keypress, game);

    mlx_loop_hook(game->mlx->mlx, render_frame, game);

	mlx_loop(game->mlx->mlx);
    return (true);
}

int handle_close(t_game *game)
{
    free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

int handle_keypress(int keycode, t_game *game)
{
	t_axis d;

	ft_bzero(&d, sizeof(t_axis));
	if (keycode == KEY_ESC)
		handle_close(game);
	else if (keycode == KEY_W)
	{
		d.y = -1;
		game->player.dir = UP;
	}
	else if (keycode == KEY_A)
	{
		d.x = -1;
		game->player.dir = LEFT;
	}
	else if (keycode == KEY_S)
	{
		d.y = 1;
		game->player.dir = DOWN;
	}
	else if (keycode == KEY_D)
	{
		d.x = 1;
		game->player.dir = RIGHT;
	}
	move_player(game, d);
	return (0);
}

static int	render_frame(t_game *game)
{
	if (get_elapsed_ms(game) >= 300)
	{
		update_enemies(game);
		game->data.last_update = get_current_time_ms();
	}
	draw_map(game);
	return (0);
}


