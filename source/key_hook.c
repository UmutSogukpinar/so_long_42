/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:29:34 by umut              #+#    #+#             */
/*   Updated: 2024/12/28 23:01:30 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"
#include "mlx.h"
#include "ft_printf.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		ft_printf("User enter \"ESC\" button. Game shuts down");
		close_window(game);
	}
	else if (keycode == 119)
		forward_movement(game);
	else if (keycode == 115)
		backward_movement(game);
	else if (keycode == 100)
		right_movement(game);
	else if (keycode == 97)
		left_movement(game);
	return (0);
}
