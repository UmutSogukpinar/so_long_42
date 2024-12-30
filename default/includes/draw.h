/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:54:03 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/30 18:52:59 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "so_long.h"

void	init_images(t_game *game);

void	init_ground(t_game *game);
void	init_fox(t_game *game);
void	init_wall(t_game *game);
void	init_collectible(t_game *game);
void	init_exit(t_game *game);

void	draw_ground(t_game *game);
void	draw_fox(t_game *game);
void	draw_wall(t_game *game);
void	draw_collectible(t_game *game);
void	draw_exit(t_game *game);

#endif