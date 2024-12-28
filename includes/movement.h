/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:44:01 by umut              #+#    #+#             */
/*   Updated: 2024/12/28 22:54:40 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

#include "so_long.h"

void	forward_movement(t_game *game);
void	backward_movement(t_game *game);

int		is_wall(char c);

#endif