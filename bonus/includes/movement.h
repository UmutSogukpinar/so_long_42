/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:54:34 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/30 14:06:36 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

# include "so_long.h"

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