#include "../../includes/game.h"

bool	display_error_msg(char *msg, bool is_perror)
{
	ft_putendl_fd(ERR, STDERR_FILENO);
	ft_putendl_fd(ERR_BAR, STDERR_FILENO);
	if (msg)
	{
		if (is_perror)
			perror(msg);
		else
			ft_putendl_fd(msg, STDERR_FILENO);
	}
	ft_putendl_fd(ERR_BAR, STDERR_FILENO);
	return (false);
}

void	display_count_move(int count)
{
	ft_putstr_fd("Move Count: ", STDOUT_FILENO);
	ft_putnbr_fd(count, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
}
