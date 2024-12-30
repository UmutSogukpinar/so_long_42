/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:59:16 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/30 18:47:15 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_printf.h"
#include "movement.h"

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
