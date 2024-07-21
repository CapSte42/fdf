/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_related_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:08:52 by smontuor          #+#    #+#             */
/*   Updated: 2024/07/21 08:33:08 by smontuor         ###   ########.fr       */
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

static int	right_board_hook(int keycode, t_fdf *fdf)
{
	if (keycode == XK_Left)
		fdf->rot_y -= fdf->acceleration;
	if (keycode == XK_Right)
		fdf->rot_y += fdf->acceleration;
	if (keycode == XK_Up)
		fdf->rot_x -= fdf->acceleration;
	if (keycode == XK_Down)
		fdf->rot_x += fdf->acceleration;
	if (keycode == XK_KP_Add)
		update_z(fdf, 1);
	if (keycode == XK_KP_Subtract)
		update_z(fdf, -1);
	if (keycode == XK_g)
	{
		if (fdf->is_sphere == 0)
			fdf->is_sphere = 1;
		else
			fdf->is_sphere = 0;
	}
	return (0);
}

static int	left_board_hook(int keycode, t_fdf *fdf)
{
	if (keycode == XK_Escape)
		ft_cool_exit(fdf);
	if (keycode == XK_r)
		reset_z(fdf);
	if (keycode == XK_space)
		set_zoom_and_center(fdf);
	if (keycode == XK_h)
		my_mlx_put_image_to_window(fdf, 1);
	if (keycode == XK_a)
		fdf->rot_z += fdf->acceleration;
	if (keycode == XK_d)
		fdf->rot_z -= fdf->acceleration;
	if (keycode == XK_q)
	{
		if (fdf->acceleration < 5)
			fdf->acceleration += 0.1;
	}
	if (keycode == XK_w)
	{
		if (fdf->acceleration > 0.1)
			fdf->acceleration -= 0.1;
	}
	if (keycode == XK_1)
		change_earth_color(fdf);
	if (keycode == XK_2)
		change_stroboscope_color(fdf);
	if (keycode == XK_3)
		change_shadowed_color(fdf);
	if (keycode == XK_4)
		reset_colors(fdf);
	return (0);
}

void	projection_setup(t_fdf *fdf)
{
	if (fdf->zoom.scaling == 0)
		fdf->zoom.scaling = 1;
	clear_image(fdf);
	if (fdf->is_sphere == 1)
		apply_flat_to_sphere(fdf);
	else if (fdf->is_right_button_pressed == 0)
		isometric_projection(fdf);
	else
		go_parallel(fdf);
	if (fdf->is_sphere == 1)
		deploy_sphere(fdf);
	else
		deploy_map(fdf);
	my_mlx_put_image_to_window(fdf, 0);
}

int	key_hook(int keycode, t_fdf *fdf)
{
	calculate_look_at_for_height_map(fdf);
	right_board_hook(keycode, fdf);
	left_board_hook(keycode, fdf);
	projection_setup(fdf);
	return (0);
}
