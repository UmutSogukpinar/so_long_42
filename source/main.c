/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:10:50 by umut              #+#    #+#             */
/*   Updated: 2024/12/22 17:31:35 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "map.h"
#include "libft.h"
#include "stdio.h"

void	init_game(t_game *game, char *arg)
{
	game -> filename = ft_strdup(arg);
	game -> exit = 0;
	game -> moves = 0;
	init_map(game);
	game -> y = (count_lines(game -> filename) * SQUARE_PIXEL);
	game -> x = (count_column(game -> filename) * SQUARE_PIXEL);
	game -> name = ft_strdup("so_long");
}



int	main(int arg_number, char **args)
{
	t_game game;

	if (arg_number == 2)
	{
		init_game(&game, args[1]);
		// game.mlx = mlx_init();
		// game.screen = mlx_new_window(game.mlx, game.x, game.y, game.name);
	
		// mlx_loop(game.mlx);
	}

	printf("game name: %s \n game exit: %d\n game x axis: %d\n", game.name, game.exit, game.x);
}
