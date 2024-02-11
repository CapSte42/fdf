/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:59:24 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/11 13:12:02 by smontuor         ###   ########.fr       */
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

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = (unsigned int)color;
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		ft_exit_error("Yeah. Whatever.");
	ft_checkfile(av[1], &fdf);
	fdf.index = fdf.y_axis * fdf.x_axis;
/*------------------------------------------------*/
	print_coords(&fdf);
/*------------------------------------------------*/
	fdf.mlx = mlx_init();
	fdf.mlx_win = mlx_new_window(fdf.mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT, fdf.name);
	fdf.img.img = mlx_new_image(fdf.mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel, &fdf.img.line_length, &fdf.img.endian);
	int zoom;
	zoom = 20;
	i = 0;
	t_coords start;
	t_coords end;

	// start.color = 0x00FF0000;
	// end.color = 0x00FF0000;

	while (i < fdf.index) {
    	start.x = fdf.coords[i].x * zoom;
    	start.y = fdf.coords[i].y * zoom;
		start.color = fdf.coords[i].color;

    // Disegna linea orizzontale se non siamo all'ultimo punto sull'asse X
    	if (i % fdf.x_axis != fdf.x_axis - 1) {
    	    end.x = fdf.coords[i + 1].x * zoom;
    	    end.y = start.y; // Mantieni end.y uguale a start.y per una linea orizzontale
			end.color = fdf.coords[i + 1].color;
    	    drawline(&fdf, start.x, start.y, end.x, end.y, start.color, end.color);
    	}

    	// Disegna linea verticale se non siamo all'ultima riga
    	if (i < fdf.index - fdf.x_axis) {
    	    end.x = start.x; // Mantieni end.x uguale a start.x per una linea verticale
    	    end.y = fdf.coords[i + fdf.x_axis].y * zoom;
			end.color = fdf.coords[i + fdf.x_axis].color;
    	    drawline(&fdf, start.x, start.y, end.x, end.y, start.color, end.color);
    	}

    	i++;
	}

	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img.img, 0, 0);
	mlx_hook(fdf.mlx_win, DestroyNotify, StructureNotifyMask, ft_cool_exit, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}

