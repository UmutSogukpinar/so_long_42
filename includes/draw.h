/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 23:09:38 by umut              #+#    #+#             */
/*   Updated: 2024/12/26 01:16:29 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

#include "so_long.h"

int	init_images(t_game *game);

int	init_ground(t_game *game);

int	draw_ground(t_game *game);

#endif