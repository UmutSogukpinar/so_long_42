/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:56:43 by umut              #+#    #+#             */
/*   Updated: 2024/12/25 18:29:59 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define CELL_LEN 50

typedef struct s_img
{
	void	*img;

}	t_img;

typedef struct s_player
{
	int		y;
	int		x;
	t_img	img;

}	t_player;

typedef struct s_game
{
	char		**map;
	char		*filename;
	char		*name;
	int			exit;
	int			moves;
	void		*mlx;
	void		*screen;
	int			screen_y;
	int			screen_x;
	t_player	player;

}	t_game;

void	free_game(t_game *game);
void free_game_sub_one(t_game *game);
void free_game_sub_two(t_game *game);

#endif