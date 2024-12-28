/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:35:25 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/29 00:34:31 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "so_long.h"

int	init_map(t_game *game);

int	is_line(char *line);
int	count_lines(char *file_name);
int	count_columns(char *file_name);
int	generate_map_struct(char *file_name, char **map_struct);

int	get_total_collectible(t_game *game);
#endif