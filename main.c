/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:59:24 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/08 19:47:29 by smontuor         ###   ########.fr       */
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
	fdf.tot_punti = fdf.tot_colonna * fdf.tot_riga;
	int i = 0;
/*------------------------------------------------*/
	for(int y = 0; y < fdf.tot_riga; y++)
	{
		for(int x = 0; x < fdf.tot_colonna; x++)
		{
			printf("coords.x = %d , coords.y = %d , coords.z = %f , color = %ld\n", fdf.coords[i].x, fdf.coords[i].y, fdf.coords[i].z, fdf.coords[i].color);
			i++;
		}
	}
	printf("tot_colonna = %d , tot_riga = %d , tot_punti = %d\n", fdf.tot_colonna, fdf.tot_riga, fdf.tot_punti);

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

	start.color = 0x00FF0000;
	end.color = 0x00FF0000;

for (i = 0; i < fdf.tot_punti; i++)
{
    // Draw line to the next point in the same row
    if (fdf.coords[i].x == fdf.coords[i+1].x) // Check if there is a next point in the same row
    {
        start.x = fdf.coords[i].x * zoom;
        start.y = fdf.coords[i].y * zoom;
        end.x = fdf.coords[i+1].x * zoom;
        end.y = fdf.coords[i+1].y * zoom;
        bresenham(&fdf.img, &start, &end);
    }


    if (i < 32) // Check if there is a next row
    {
        start.x = fdf.coords[i].x * zoom;
        start.y = fdf.coords[i].y * zoom;
        end.x = fdf.coords[i+fdf.tot_colonna].x * zoom;
        end.y = fdf.coords[i+fdf.tot_colonna].y * zoom;
        bresenham(&fdf.img, &start, &end);
    }
}
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img.img, 100, 100);
	mlx_hook(fdf.mlx_win, DestroyNotify, StructureNotifyMask, ft_cool_exit, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}

