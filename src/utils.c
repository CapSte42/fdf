/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:06:21 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/29 12:25:01 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_iso_coords(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->index)
	{
		fdf->coords->iso_x = fdf->coords->x;
		fdf->coords->iso_y = fdf->coords->y;
		i++;
	}
}

void	put_menu_win(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	while (x < 250)
	{
		y = 0;
		while (y < DEFAULT_HEIGHT)
		{
			my_mlx_pixel_put(&(fdf->img), x, y, 0x333333);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
}
