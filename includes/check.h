/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 01:57:39 by umut              #+#    #+#             */
/*   Updated: 2024/12/29 11:12:40 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

#include "so_long.h"

void	game_check(t_game *game);

void	null_check(t_game *game);
void	game_check_utils_one(t_game *game);

int		is_map_rectangular(t_game *game);
int		check_map_sides(t_game *game);

int		all_collectibles_gathered(t_game *game);

#endif