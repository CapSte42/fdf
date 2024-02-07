/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:59:24 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/06 10:48:33 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int ac, char **av)
{
	t_coords	*coords;
	int	tot_punti;

	if (ac != 2)
		ft_exit_error("Yeah. Whatever.");
	tot_punti = ft_checkfile(av[1], &coords);
/*........................*/
	for(int i = 0; i < tot_punti; i++)
	{
		printf("coords.x = %d , coords.y = %d , coords.z = %f , color = %ld\n", coords[i].x, coords[i].y, coords[i].z, coords[i].color);
	}
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	color = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, av[1]);
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	int n = 0;
	while(1)
	{
		for(int i = 0; i < tot_punti; i++)
		{
			my_mlx_pixel_put(&img, coords[i].y + (coords[i].y * 25), coords[i].x + (coords[i].x * 60), coords[i].color);
			n += 10;
		}
		/* mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); */
		sleep(6);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 100);
		mlx_loop(mlx);
	}
	ft_free_n(1, 0, &coords);
}

