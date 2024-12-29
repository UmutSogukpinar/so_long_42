/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:44:01 by umut              #+#    #+#             */
/*   Updated: 2024/12/29 01:54:34 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

#include "so_long.h"

void	forward_movement(t_game *game);
void	forward_movement_two(t_game *game, char target, char current);
void	backward_movement(t_game *game);
void	backward_movement_two(t_game *game, char target, char current);
void	right_movement(t_game *game);
void	right_movement_two(t_game *game, char target, char current);
void	left_movement(t_game *game);
void	left_movement_two(t_game *game, char target, char current);

int		is_wall(char c);
int		is_ground(char c);
int		is_collectible(char c);
int		is_exit(char c);

#endif