/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 22:01:22 by umut              #+#    #+#             */
/*   Updated: 2024/12/24 23:14:46 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void free_game(t_game *game)
{
	free_game_sub_one(game);
}

void free_game_sub_one(t_game *game)
{
	int	i;

	i = 0;
	if (game -> filename)
		free(game->filename);
	if (game -> name)
		free(game->name);
	while ((game->map)[i] != NULL)
	{
		free((game->map)[i]);
		i++;
	}
	free(game->map);
}
