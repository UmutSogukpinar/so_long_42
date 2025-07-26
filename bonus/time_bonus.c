#include "../includes/game.h"
#include <sys/time.h>

t_ms	get_elapsed_ms(t_game *game)
{
	struct timeval	now;
	t_ms			now_ms;

	if (gettimeofday(&now, NULL) == -1)
    {
        display_error_msg(GETTIMEOFDAY_ERR, true);
        free_game(game);
        exit(EXIT_FAILURE);
    }
	now_ms = now.tv_sec * 1000 + now.tv_usec / 1000;
	return (now_ms - game->data.last_update);
}

t_ms	get_current_time_ms(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

