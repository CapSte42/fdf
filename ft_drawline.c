/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:54:56 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/13 12:21:58 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_coords_and_colors(t_draw *draw, t_coords start, t_coords end)
{
	draw->x0 = start.iso_x;
	draw->y0 = start.iso_y;
	draw->x1 = end.iso_x;
	draw->y1 = end.iso_y;
	draw->start_color = start.color;
	draw->end_color = end.color;
	draw->start_r = (draw->start_color >> 16) & 0xFF;
	draw->start_g = (draw->start_color >> 8) & 0xFF;
	draw->start_b = draw->start_color & 0xFF;
	draw->end_r = (draw->end_color >> 16) & 0xFF;
	draw->end_g = (draw->end_color >> 8) & 0xFF;
	draw->end_b = draw->end_color & 0xFF;
	draw->current_r = draw->start_r;
	draw->current_g = draw->start_g;
	draw->current_b = draw->start_b;
}

static void	calculate_drawing_params(t_draw *draw)
{
	draw->dx = abs(draw->x1 - draw->x0);
	if (draw->x0 < draw->x1)
		draw->sx = 1;
	else
		draw->sx = -1;
	draw->dy = -abs(draw->y1 - draw->y0);
	if (draw->y0 < draw->y1)
		draw->sy = 1;
	else
		draw->sy = -1;
	draw->err = draw->dx + draw->dy;
	draw->e2 = 0;
	draw->steps = fmax(abs(draw->x1 - draw->x0), abs(draw->y1 - draw->y0));
	draw->color_step_r = (float)(draw->end_r - draw->start_r) / draw->steps;
	draw->color_step_g = (float)(draw->end_g - draw->start_g) / draw->steps;
	draw->color_step_b = (float)(draw->end_b - draw->start_b) / draw->steps;
}

void	set_draw(t_draw *draw, t_coords start, t_coords end) //cazzi
{
	set_coords_and_colors(draw, start, end);
	calculate_drawing_params(draw);
}

static void	set_current_color(t_draw *draw)
{
	draw->current_color = ((int)draw->current_r << 16)
		| ((int)draw->current_g << 8)
		| (int)draw->current_b;
}

void	drawline(t_fdf *fdf, t_coords start, t_coords end)
{
	t_draw	draw;

	set_draw(&draw, start, end);
	while (!(draw.x0 == draw.x1 && draw.y0 == draw.y1))
	{
		set_current_color(&draw);
		my_mlx_pixel_put(&fdf->img, draw.x0, draw.y0, draw.current_color);
		draw.e2 = 2 * draw.err;
		if (draw.e2 >= draw.dy)
		{
			draw.err += draw.dy;
			draw.x0 += draw.sx;
		}
		if (draw.e2 <= draw.dx)
		{
			draw.err += draw.dx;
			draw.y0 += draw.sy;
		}
		draw.current_r += draw.color_step_r;
		draw.current_g += draw.color_step_g;
		draw.current_b += draw.color_step_b;
		draw.current_r = fmax(0, fmin(255, draw.current_r));
		draw.current_g = fmax(0, fmin(255, draw.current_g));
		draw.current_b = fmax(0, fmin(255, draw.current_b));
	}
}
