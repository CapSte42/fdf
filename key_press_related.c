/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_related.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:38:22 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/13 23:21:49 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < DEFAULT_HEIGHT)
	{
		j = 0;
		while (j < DEFAULT_WIDTH)
		{
			my_mlx_pixel_put(&fdf->img, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

void	update_z(t_fdf *info, int flag)
{
	int	i;

	i = 0;
	while (i < info->index)
	{
		if (info->coords[i].is_zero == 0)
		{
			info->coords[i].z += flag;
			info->z_mod += flag;
		}
		i++;
	}
}

void	reset_z(t_fdf *info)
{
	int i = 0;

	if (info->z_mod < 0)
	{
	    while (i < info->index)
	    {
	        if (info->coords[i].is_zero == 0)
	            info->coords[i].z -= info->z_mod;
	        i++;
	    }
	}
	else if (info->z_mod > 0)
	{
	    while (i < info->index)
	    {
	        if (info->coords[i].is_zero == 0)
	            info->coords[i].z -= info->z_mod;
	        i++;
	    }
	}
	info->z_mod = 0;
}

int rotate(t_fdf *info) {
    int i;
    double new_x;
    double new_y;
    double angle_radians = PI / 180; // One degree in radians

    i = 0;
    while (i < info->index) {

        // 1. Translate to origin
        new_x = info->coords[i].iso_x - info->zoom.center_x;
        new_y = info->coords[i].iso_y - info->zoom.center_y;

        // 2. Apply rotation matrix
        info->coords[i].iso_x = info->zoom.center_x + (new_x * cos(angle_radians) - new_y * sin(angle_radians));
        info->coords[i].iso_y = info->zoom.center_y + (new_x * sin(angle_radians) + new_y * cos(angle_radians));

        i++;
    }
	return (1);
}


int	key_hook(int keycode, t_fdf *fdf)
{
	int flag;

	flag = 0;
	if (keycode == XK_Escape)
		ft_cool_exit(fdf); //done
	if (keycode == XK_Left)
		flag = rotate(fdf);
	if (keycode == XK_Right)
		fdf->zoom.center_y += 10;
	if (keycode == XK_Up)
		fdf->zoom.center_x -= 10;
	if (keycode == XK_Down)
		fdf->zoom.center_x += 10;
	if (keycode == XK_KP_Add) //done
		update_z(fdf, 1);
	if (keycode == XK_KP_Subtract) //done
		update_z(fdf, -1);
	if (keycode == XK_r) //done
		reset_z(fdf);
	if (keycode == XK_c)
		fdf->zoom.angle -= 1;
	if (keycode == XK_space) //almost done
		set_zoom_and_center(fdf);
	if (keycode == XK_h) //done
		my_mlx_put_image_to_window(fdf, 1);

	clear_image(fdf);
	if (flag == 0)
		isometric_projection(fdf);
	deploy_map(fdf);
	my_mlx_put_image_to_window(fdf, 0);
	return (0);
}

