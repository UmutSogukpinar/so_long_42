/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:26:26 by umut              #+#    #+#             */
/*   Updated: 2024/12/26 01:34:45 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "unistd.h"
#include "draw.h"
#include "mlx.h"
#include "libft.h"

int	init_images(t_game *game)
{
	int		is_successful;

	is_successful = init_ground(game);
	if (is_successful == -1)
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
    char *xpm_path = "./images/grass.xpm";  // ft_strdup gereksiz, direkt string kullanabilirsiniz

    // game->mlx'in geçerli olup olmadığını kontrol et
    if (!game || !game->mlx)
    {
        perror("Error: Invalid mlx context");
        return (-1);
    }

    // XPM dosyasını yükle
    game->ground_img = mlx_xpm_file_to_image(game->mlx, xpm_path, &width, &height);
    
    // Eğer görsel yüklenemezse
    if (!(game->ground_img))
    {
        perror("Error: Failed to load XPM image");
        return (-1);
    }

    // Eğer görsel başarıyla yüklendiyse
    return (0);
}

