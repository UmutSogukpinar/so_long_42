/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:53:23 by umut              #+#    #+#             */
/*   Updated: 2024/12/21 18:07:04 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "mlx.h"

int	draw_square(void *mlx, void *window, char *xpm_path, int x, int y)
{
	void	*image;
	int		width;
	int		height;

	image = mlx_xpm_file_to_image(mlx, xpm_path, &width, &height);
	if (image)
	{
		mlx_put_image_to_window(mlx, window, image, x, y);
		return (0);
	}
	else
		return (-1);
}

int	draw_window(void *mlx, void *window, char *xpm_path)
{
	char	*str;

	
}
