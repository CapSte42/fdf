/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:59:24 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/11 21:59:37 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;
	int		i;

	if (ac != 2)
		ft_exit_error("Yeah. Whatever.");
	ft_checkfile(av[1], &fdf);
	ft_start_mlx(&fdf);
	set_zoom_and_center(&fdf);
	int_to_isometric_pixel(&fdf);
	//int_to_perspective_projection(&fdf);
	i = 0;
	while (i < fdf.index)
	{
		if (fdf.coords[i].x < fdf.x_axis - 1
			&& fdf.coords[i].x < fdf.coords[i + 1].x)
			drawline(&fdf, fdf.coords[i], fdf.coords[i + 1]);
		if (fdf.coords[i].y < fdf.y_axis - 1)
			drawline(&fdf, fdf.coords[i], fdf.coords[i + fdf.x_axis]);
		i++;
	}
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img.img, 0, 0);
	mlx_hook(fdf.mlx_win, DestroyNotify, StructureNotifyMask,
		ft_cool_exit, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
