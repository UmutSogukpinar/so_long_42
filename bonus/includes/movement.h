/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:54:34 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/31 01:33:21 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

# include "so_long.h"

void	movement(t_game *game, int t_x, int t_y);
void	movement_two(t_game *game, char t_cell, char c_cell, int t_x, int t_y);
void	move_three(t_game *game, char t_cell, char c_cell, int t_x, int t_y);

int		is_wall(char c);
int		is_ground(char c);
int		is_collectible(char c);
int		is_exit(char c);
int		is_enemy(char c);

#endif