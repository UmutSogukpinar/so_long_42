/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:53:54 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/30 14:06:30 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "so_long.h"

void	game_check(t_game *game);

void	null_check(t_game *game);
void	game_check_utils_one(t_game *game);
void	game_check_utils_two(t_game *game);

int		is_map_rectangular(t_game *game);
int		check_map_sides(t_game *game);
int		check_invalid_elements(t_game *game);

int		all_collectibles_gathered(t_game *game);

int		accessability_check(t_game *game);
char	**copy_map(t_game *game, int rows);
int		scan_map(char **map_copy);
void	flood_fill(t_game *game, char **map_copy, int x, int y);
void	free_copy(char **map_copy);

#endif