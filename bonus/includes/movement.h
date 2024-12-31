/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:54:34 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/01 00:17:28 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

# include "so_long.h"

void	movement(t_game *game, int t_x, int t_y);
void	movement_utils(t_game *game, int t_x, int t_y);
void	enemy_collision(t_game *game);

int		is_wall(char c);
int		is_ground(char c);
int		is_collectible(char c);
int		is_exit(char c);
int		is_enemy(char c);

#endif