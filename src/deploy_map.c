/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:10:07 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/29 12:30:50 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_if_visible(t_fdf *fdf, int index1, int index2)
{
	if (fdf->coords[index1].is_visible && fdf->coords[index2].is_visible)
	{
		drawline(fdf, fdf->coords[index1], fdf->coords[index2]);
	}
}

static void	process_horizontal_lines(t_fdf *fdf, int i)
{
	int	j;
	int	index;
	int	first_index;
	int	last_index;

	j = 0;
	while (j < fdf->x_axis - 1)
	{
		index = i * fdf->x_axis + j;
		draw_line_if_visible(fdf, index, index + 1);
		j++;
	}
	first_index = i * fdf->x_axis;
	last_index = (i + 1) * fdf->x_axis - 1;
	draw_line_if_visible(fdf, last_index, first_index);
}

static void	process_vertical_lines(t_fdf *fdf, int j)
{
	int	i;
	int	index;

	i = 0;
	while (i < fdf->y_axis - 1)
	{
		index = i * fdf->x_axis + j;
		draw_line_if_visible(fdf, index, index + fdf->x_axis);
		i++;
	}
}

void	deploy_sphere(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->y_axis)
	{
		process_horizontal_lines(fdf, i);
		i++;
	}
	j = 0;
	while (j < fdf->x_axis)
	{
		process_vertical_lines(fdf, j);
		j++;
	}
}

void	deploy_map(t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->z_max = fdf->coords[0].z;
	fdf->z_min = fdf->coords[0].z;
	while (i < fdf->index - 1)
	{
		if (fdf->coords[i].x < fdf->x_axis - 1
			&& fdf->coords[i].x < fdf->coords[i + 1].x)
		{
			drawline(fdf, fdf->coords[i], fdf->coords[i + 1]);
			if (fdf->coords[i].z > fdf->z_max)
				fdf->z_max = fdf->coords[i].z;
			if (fdf->coords[i].z < fdf->z_min)
				fdf->z_min = fdf->coords[i].z;
		}
		if (fdf->coords[i].y < fdf->y_axis - 1)
			drawline(fdf, fdf->coords[i], fdf->coords[i + fdf->x_axis]);
		i++;
	}
}
