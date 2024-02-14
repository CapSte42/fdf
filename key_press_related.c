/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_related.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:38:22 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/14 01:20:40 by smontuor         ###   ########.fr       */
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

// int rotate(t_fdf *info) {
//     int i;
//     double new_x;
//     double new_y;
//     double angle_radians = PI / 180; // One degree in radians

//     i = 0;
//     while (i < info->index) {

//         // 1. Translate to origin
//         new_x = info->coords[i].iso_x - info->zoom.center_x;
//         new_y = info->coords[i].iso_y - info->zoom.center_y;

//         // 2. Apply rotation matrix
//         info->coords[i].iso_x = info->zoom.center_x + (new_x * cos(angle_radians) - new_y * sin(angle_radians));
//         info->coords[i].iso_y = info->zoom.center_y + (new_x * sin(angle_radians) + new_y * cos(angle_radians));
//         i++;
//     }
// 	return (1);
// }

void apply_rotation(t_fdf *info, int i) {
    double x, y, z;
    double rx, ry, rz;
    double cosx = cos(info->rot_x), sinx = sin(info->rot_x);
    double cosy = cos(info->rot_y), siny = sin(info->rot_y);
    double cosz = cos(info->rot_z), sinz = sin(info->rot_z);

    x = info->coords[i].x;
    y = info->coords[i].y;
    z = info->coords[i].z;

    // Rotazione intorno all'asse X
    ry = y * cosx - z * sinx;
    rz = y * sinx + z * cosx;
    y = ry;
    z = rz;

    // Rotazione intorno all'asse Y
    rx = x * cosy + z * siny;
    rz = -x * siny + z * cosy;
    x = rx;
    z = rz;

    // Rotazione intorno all'asse Z
    rx = x * cosz - y * sinz;
    ry = x * sinz + y * cosz;
    x = rx;
    y = ry;

    // Applicazione della proiezione isometrica dopo la rotazione
    info->coords[i].iso_x = info->zoom.center_x + ((x - y) * cos(PI / 6) * info->zoom.scaling);
    info->coords[i].iso_y = info->zoom.center_y - (z * sin(PI / 6) * info->zoom.scaling) + ((x + y) * sin(PI / 6) * info->zoom.scaling);
}

void isometric_projection_with_rotation(t_fdf *info) {
    int i;

    i = 0;
    while (i < info->index) {
        apply_rotation(info, i);
        i++;
    }
}



int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == XK_Escape)
		ft_cool_exit(fdf); //done
	if (keycode == XK_Left)
		fdf->rot_y -= 0.1;
	if (keycode == XK_Right)
		fdf->rot_y += 0.1;
	if (keycode == XK_Up)
		fdf->rot_x -= 0.1;
	if (keycode == XK_Down)
		fdf->rot_x += 0.1;
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
	if (keycode == XK_a) //done
		fdf->rot_z += 0.1;
	if (keycode == XK_d) //done
		fdf->rot_z -= 0.1;

	clear_image(fdf);
	isometric_projection_with_rotation(fdf);
	deploy_map(fdf);
	my_mlx_put_image_to_window(fdf, 0);
	return (0);
}

