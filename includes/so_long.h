/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:56:43 by umut              #+#    #+#             */
/*   Updated: 2024/12/29 01:42:37 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define CELL_LEN 50

typedef struct s_player
{
	int		y;
	int		x;
	void	*img;

}	t_player;

typedef struct s_game
{
	char		**map;
	char		*filename;
	char		*name;
	void		*mlx;
	void		*screen;

	void		*ground_img;
	void		*wall_img;
	void		*collect_img;
	void		*exit_img;

	int			screen_y;
	int			screen_x;
	int			moves;
	int			total_collectible;
	int			gathered_collectible;
	t_player	*player;

}	t_game;

void	init_game(t_game *game, char **args);
void	init_game_att_one(t_game *game, char *arg);
void	init_game_att_two(t_game *game);
void	draw_images(t_game *game);

int		key_hook(int keycode, t_game *game);
int		close_window(void *param);


void	free_game(t_game *game);
void	free_game_sub_one(t_game *game);
void	free_game_sub_two(t_game *game);
void	free_game_sub_three(t_game *game);

#endif