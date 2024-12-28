/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:26:26 by umut              #+#    #+#             */
/*   Updated: 2024/12/27 16:18:08 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "unistd.h"
#include "draw.h"
#include "mlx.h"
#include "libft.h"

void init_images(t_game *game)
{
    init_ground(game);
    init_fox(game);
    init_wall(game);
}

void init_ground(t_game *game)
{
    int width;
    int height;
    char *xpm_path;

    xpm_path = ft_strdup("./images/grass.xpm");
    if (!game || !game->mlx)
    {
        perror("Error: Invalid mlx context");
        free(xpm_path);
        close_window(game);
    }
    game->ground_img = mlx_xpm_file_to_image(game->mlx, xpm_path, &width, &height);
    if (!(game->ground_img))
    {
        perror("Error: Failed to load XPM image");
        free(xpm_path);
        close_window(game);
    }
    free(xpm_path);
}

void init_fox(t_game *game)
{
    int width;
    int height;
    char *xpm_path;

    xpm_path = ft_strdup("./images/fox.xpm");
    if (!game || !game->mlx)
    {
        perror("Error: Invalid mlx context");
        free(xpm_path);
        close_window(game);
    }
    game -> player -> img = mlx_xpm_file_to_image(game->mlx, xpm_path, &width, &height);
    if (!(game-> player -> img))
    {
        perror("Error: Failed to load XPM image");
        free(xpm_path);
        close_window(game);
    }
    free(xpm_path);
}

void init_wall(t_game *game)
{
    int width;
    int height;
    char *xpm_path;

    xpm_path = ft_strdup("./images/wall.xpm");
    if (!game || !game->mlx)
    {
        perror("Error: Invalid mlx context");
        free(xpm_path);
        close_window(game);
    }
    game -> wall_img = mlx_xpm_file_to_image(game->mlx, xpm_path, &width, &height);
    if (!(game -> wall_img))
    {
        perror("Error: Failed to load XPM image");
        free(xpm_path);
        close_window(game);
    }
    free(xpm_path);
}