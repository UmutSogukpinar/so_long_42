/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:56:43 by umut              #+#    #+#             */
/*   Updated: 2024/12/22 12:34:42 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SQUARE_PIXEL 50

typedef struct s_img
{
	void	*img;
}t_img;

typedef struct s_player
{
	int		y;
	int		x;
	t_img	img;
	
}t_player;

typedef struct s_game
{
	char		**map;
	char		*filename;
	char		*name;
	int			y;
	int			x;
	int			exit;
	int			moves;
	void		*mlx;
	void		*screen;
	t_player	player;

}t_game;


#endif