/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 23:09:38 by umut              #+#    #+#             */
/*   Updated: 2024/12/27 11:16:39 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

#include "so_long.h"

void	init_images(t_game *game);

void	init_ground(t_game *game);
void	init_fox(t_game *game);

void	draw_ground(t_game *game);
void	draw_fox(t_game *game);

#endif