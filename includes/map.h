/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:35:25 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/22 13:16:41 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

int	init_map(t_game *game);

int is_line(char *line);
int	count_lines(char *file_name);
int	count_column(char *file_name);
int	generate_map_struct(char *file_name, char **map_struct);

#endif