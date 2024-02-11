/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:59:24 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/11 20:43:51 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

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
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = (unsigned int)color;
	}
}

void	ft_start_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT, fdf->name);
	fdf->img.img = mlx_new_image(fdf->mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
}

void	set_zoom_and_center(t_fdf *fdf)
{
	fdf->zoom.scaling = (fmin(DEFAULT_WIDTH / fdf->x_axis, DEFAULT_HEIGHT / fdf->y_axis)) / 2;
	fdf->zoom.center_x = DEFAULT_WIDTH / 2;
	fdf->zoom.center_y = (DEFAULT_HEIGHT / 2) - (fdf->y_axis * fdf->zoom.scaling / 2);
}

void int_to_isometric_pixel(t_fdf *info)
{
    int i;

	i = 0;
    while (i < info->index)
	{
		info->coords[i].iso_x = (info->zoom.center_x) + ((info->coords[i].x - info->coords[i].y)
				* cos(PI / 6) * info->zoom.scaling);
		info->coords[i].iso_y = (info->zoom.center_y) - (info->coords[i].z * sin(PI / 6)
				* info->zoom.scaling) + ((info->coords[i].x + info->coords[i].y)
				* sin(PI / 6) * info->zoom.scaling);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		ft_exit_error("Yeah. Whatever.");
	ft_checkfile(av[1], &fdf);
	ft_start_mlx(&fdf);
	set_zoom_and_center(&fdf);
	int_to_isometric_pixel(&fdf);
	//print_coords(&fdf);
	//isometric_projection(&fdf);
	//applyZoomAndCenter(&fdf);
	int i = 0;
	while (i < fdf.index)
	{
		if (fdf.coords[i].x < fdf.x_axis - 1 && fdf.coords[i].x < fdf.coords[i + 1].x)
			drawline(&fdf, fdf.coords[i], fdf.coords[i + 1]);
		if (fdf.coords[i].y < fdf.y_axis - 1)
			drawline(&fdf, fdf.coords[i], fdf.coords[i + fdf.x_axis]);
		i++;
	}

	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img.img, 0, 0);
	mlx_hook(fdf.mlx_win, DestroyNotify, StructureNotifyMask, ft_cool_exit, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
