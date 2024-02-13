/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_related.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:28:33 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/13 20:32:42 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_cool_exit(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	mlx_destroy_display(fdf->mlx);
	ft_free_n(3, 0, &fdf->mlx, &fdf->coords, &fdf->name);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < DEFAULT_WIDTH && y >= 0 && y < DEFAULT_HEIGHT)
	{
		dst = data->addr
			+ (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = (unsigned int)color;
	}
}

void	ft_start_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, DEFAULT_WIDTH,
			DEFAULT_HEIGHT, fdf->name);
	fdf->img.img = mlx_new_image(fdf->mlx, DEFAULT_WIDTH,
			DEFAULT_HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
}

void	clear_menu_win(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < DEFAULT_HEIGHT)
	{
		j = 0;
		while (j < MENU_WIDTH)
		{
			my_mlx_pixel_put(&fdf->img, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

void	my_mlx_put_image_to_window(t_fdf *fdf, int flag)
{
	static int	i;

	if (flag == 1 || i == 0)
		i++;
	if (i % 2 == 0)
		clear_menu_win(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	if (i % 2 != 0)
	{
		put_menu_win(fdf);
		write_menu(fdf);
	}
	put_signature(fdf);
}
