/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:59:24 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/29 12:41:47 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		ft_exit_error("Yeah. Whatever.");
	fdf.is_sphere = 0;
	fdf.is_left_button_pressed = 0;
	fdf.is_right_button_pressed = 0;
	ft_checkfile(av[1], &fdf);
	ft_start_mlx(&fdf);
	set_is_zero(&fdf);
	reset_iso_coords(&fdf);
	calculate_look_at_for_height_map(&fdf);
	set_zoom_and_center(&fdf);
	projection_setup(&fdf);
	my_mlx_put_image_to_window(&fdf, 0);
	mlx_hook(fdf.mlx_win, DestroyNotify, StructureNotifyMask,
		ft_cool_exit, &fdf);
	mlx_hook(fdf.mlx_win, KeyPress, KeyPressMask, key_hook, &fdf);
	mlx_hook(fdf.mlx_win, ButtonPress, ButtonPressMask, mouse_hook, &fdf);
	mlx_hook(fdf.mlx_win, MotionNotify, PointerMotionMask, mouse_move, &fdf);
	mlx_hook(fdf.mlx_win, ButtonRelease, ButtonReleaseMask,
		mouse_release_hook, &fdf);
	mlx_hook(fdf.mlx_win, Expose, ExposureMask, expose_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
