/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:59:24 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/12 15:30:30 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

void	deploy_map(t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->z_max = fdf->coords[0].z;
	fdf->z_min = fdf->coords[0].z;
	while (i < fdf->index)
	{
		if (fdf->coords[i].x < fdf->x_axis - 1
			&& fdf->coords[i].x < fdf->coords[i + 1].x)
		{
			drawline(fdf, fdf->coords[i], fdf->coords[i + 1]);
			if (fdf->coords[i].z > fdf->z_max)
				fdf->z_max = fdf->coords[i].z;
			if (fdf->coords[i].z < fdf->z_min)
				fdf->z_min = fdf->coords[i].z;
		}
		if (fdf->coords[i].y < fdf->y_axis - 1)
			drawline(fdf, fdf->coords[i], fdf->coords[i + fdf->x_axis]);
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
	isometric_projection(&fdf);
	//conic_projection(&fdf);
	deploy_map(&fdf);
	my_mlx_put_image_to_window(&fdf);
	mlx_hook(fdf.mlx_win, DestroyNotify, StructureNotifyMask,
		ft_cool_exit, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
