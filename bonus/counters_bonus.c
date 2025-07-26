#include "../includes/game.h"

static void	draw_digits_from_str_at(t_game *game, char *str, int start_x);
static char	*ft_utoa(size_t n);

bool	init_counter_textures(t_game *game)
{
	char	*paths[10];
	int		i;

	paths[0] = COUNTER_0_PATH;
	paths[1] = COUNTER_1_PATH;
	paths[2] = COUNTER_2_PATH;
	paths[3] = COUNTER_3_PATH;
	paths[4] = COUNTER_4_PATH;
	paths[5] = COUNTER_5_PATH;
	paths[6] = COUNTER_6_PATH;
	paths[7] = COUNTER_7_PATH;
	paths[8] = COUNTER_8_PATH;
	paths[9] = COUNTER_9_PATH;
	i = 0;
	while (i < 10)
	{
		game->counters[i].img = mlx_xpm_file_to_image(game->mlx->mlx,
				paths[i], &game->counters[i].width,
				&game->counters[i].height);
		if (!game->counters[i].img)
			return (false);
		i++;
	}
	return (true);
}

void	draw_move_counter(t_game *game)
{
	char	*str;
	int		start_x;

	str = ft_utoa(game->data.move_count);
	if (!str)
	{
		display_error_msg("Memory error: failed to convert move count", false);
		return ;
	}
	start_x = 8;
	draw_digits_from_str_at(game, str, start_x);
	free(str);
}

static void	draw_digits_from_str_at(t_game *game, char *str, int start_x)
{
	int	i;
	int	x;
	int	digit;

	i = 0;
	x = start_x;
	while (str[i])
	{
		digit = str[i] - '0';
		if (digit >= 0 && digit <= 9 && game->counters[digit].img)
		{
			if (mlx_put_image_to_window(game->mlx->mlx,
					game->mlx->win,
					game->counters[digit].img,
					x, DIGIT_POS_Y) == -1)
			{
				display_error_msg("Draw error: failed to render digit", true);
				return ;
			}
			x += DIGIT_SPACING;
		}
		i++;
	}
}





static char	*ft_utoa(size_t n)
{
	char	buffer[21];
	char	*result;
	int		i;

	i = 20;
	buffer[i--] = '\0';
	if (n == 0)
		buffer[i--] = '0';
	while (n > 0)
	{
		buffer[i--] = '0' + (n % 10);
		n /= 10;
	}
	result = ft_strdup(&buffer[i + 1]);
	return (result);
}


