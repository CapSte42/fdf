/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:54:56 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/11 20:38:52 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_coords_and_colors(t_draw *draw, t_coords start, t_coords end)
{
	draw->x0 = start.iso_x;
	draw->y0 = start.iso_y;
	draw->x1 = end.iso_x;
	draw->y1 = end.iso_y;
	draw->startColor = start.color;
	draw->endColor = end.color;
	draw->startR = (draw->startColor >> 16) & 0xFF;
	draw->startG = (draw->startColor >> 8) & 0xFF;
	draw->startB = draw->startColor & 0xFF;
	draw->endR = (draw->endColor >> 16) & 0xFF;
	draw->endG = (draw->endColor >> 8) & 0xFF;
	draw->endB = draw->endColor & 0xFF;
	draw->currentR = draw->startR;
	draw->currentG = draw->startG;
	draw->currentB = draw->startB;
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
	draw->colorStepR = (float)(draw->endR - draw->startR) / draw->steps;
	draw->colorStepG = (float)(draw->endG - draw->startG) / draw->steps;
	draw->colorStepB = (float)(draw->endB - draw->startB) / draw->steps;
}

static void	set_draw(t_draw *draw, t_coords start, t_coords end)
{
	set_coords_and_colors(draw, start, end);
	calculate_drawing_params(draw);
}

static void	set_current_color(t_draw *draw)
{
	draw->currentColor = ((int)draw->currentR << 16)
		| ((int)draw->currentG << 8)
		| (int)draw->currentB;
}

void	drawline(t_fdf *fdf, t_coords start, t_coords end)
{
	t_draw	draw;

	set_draw(&draw, start, end);
	while (!(draw.x0 == draw.x1 && draw.y0 == draw.y1))
	{
		set_current_color(&draw);
		my_mlx_pixel_put(&fdf->img, draw.x0, draw.y0, draw.currentColor);
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
		draw.currentR += draw.colorStepR;
		draw.currentG += draw.colorStepG;
		draw.currentB += draw.colorStepB;
		draw.currentR = fmax(0, fmin(255, draw.currentR));
		draw.currentG = fmax(0, fmin(255, draw.currentG));
		draw.currentB = fmax(0, fmin(255, draw.currentB));
	}
}
