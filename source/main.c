/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:10:50 by umut              #+#    #+#             */
/*   Updated: 2024/12/21 18:18:07 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "push_swap.h"

void	init_game(t_game *game, char *arg)
{
	game -> filename = arg[1];
	game -> exit = 0;
	game -> moves = 0;
}



int	main(int arg_number, char **args)
{
	t_game game;

	if (arg_number == 2)
	{
		init_game(&game, args[1]);
		game.mlx = mlx_init();
		//game.screen = mlx_new_window(game.mlx, x *)

		mlx_loop(game.mlx);
	}
}
