/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_related_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:08:43 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/26 22:38:02 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom_on_mouse(t_fdf *fdf, int mouseX, int mouseY)
{
	int	delta_x;
	int	delta_y;

	delta_x = mouseX - fdf->zoom.center_x;
	delta_y = mouseY - fdf->zoom.center_y;
	fdf->zoom.center_x
		= mouseX - delta_x * fdf->zoom.scaling / (fdf->zoom.scaling - 1);
	fdf->zoom.center_y
		= mouseY - delta_y * fdf->zoom.scaling / (fdf->zoom.scaling - 1);
}

int	mouse_hook(int button, int x, int y, t_fdf *fdf)
{
	if (button == 4)
	{
		fdf->zoom.scaling += 1;
		zoom_on_mouse(fdf, x, y);
	}
	else if (button == 5)
		fdf->zoom.scaling -= 1;
	else if (button == 1)
	{
		fdf->is_left_button_pressed = 1;
		fdf->initial_x = x;
		fdf->initial_y = y;
	}
	else if (button == 3)
	{
		fdf->is_right_button_pressed = 1;
		get_and_set_parallel_axis(fdf, 0);
	}
	else if (button == 2)
		set_zoom_and_center(fdf);
	projection_setup(fdf);
	return (0);
}

static void	apply_translation(t_fdf *fdf, int dx, int dy)
{
	fdf->zoom.center_x += dx;
	fdf->zoom.center_y += dy;
	projection_setup(fdf);
}

int	mouse_move(int x, int y, t_fdf *fdf)
{
	int	dx;
	int	dy;

	if (fdf->is_left_button_pressed && fdf->is_sphere == 0)
	{
		dx = x - fdf->initial_x;
		dy = y - fdf->initial_y;
		apply_translation(fdf, dx, dy);
		fdf->initial_x = x;
		fdf->initial_y = y;
	}
	return (0);
}

int	mouse_release_hook(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		fdf->is_left_button_pressed = 0;
	}
	return (0);
}
