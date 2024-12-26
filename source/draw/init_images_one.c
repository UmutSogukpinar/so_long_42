/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:26:26 by umut              #+#    #+#             */
/*   Updated: 2024/12/26 23:13:43 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "unistd.h"
#include "draw.h"
#include "mlx.h"
#include "libft.h"

int init_images(t_game *game)
{
    int is_successful;

    is_successful = 0;
    is_successful += init_ground(game);
    is_successful += init_fox(game);

    if (is_successful < 0)
    {
        perror("Error on some paths");
        return (-1);
    }
    return (0);
}

int init_ground(t_game *game)
{
    int width;
    int height;
    char *xpm_path;

    xpm_path = ft_strdup("./images/grass.xpm");
    if (!game || !game->mlx)
    {
        perror("Error: Invalid mlx context");
        return (-1);
    }
    game->ground_img = mlx_xpm_file_to_image(game->mlx, xpm_path, &width, &height);
    if (!(game->ground_img))
    {
        perror("Error: Failed to load XPM image");
        free(xpm_path);
        return (-1);
    }
    free(xpm_path);
    return (0);
}

int init_fox(t_game *game)
{
    int width;
    int height;
    char *xpm_path;

    xpm_path = ft_strdup("./images/fox.xpm");
    if (!game || !game->mlx)
    {
        perror("Error: Invalid mlx context");
        return (-1);
    }
    game -> fox_img = mlx_xpm_file_to_image(game->mlx, xpm_path, &width, &height);
    if (!(game->fox_img))
    {
        perror("Error: Failed to load XPM image");
        free(xpm_path);
        return (-1);
    }
    free(xpm_path);
    return (0);
}