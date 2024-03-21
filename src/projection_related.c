/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_related.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:33:53 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/29 14:56:15 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calc_init(t_fdf *info, t_calc *calc, int i)
{
	calc->cosx = cos(info->rot_x);
	calc->sinx = sin(info->rot_x);
	calc->cosy = cos(info->rot_y);
	calc->siny = sin(info->rot_y);
	calc->cosz = cos(info->rot_z);
	calc->sinz = sin(info->rot_z);
	calc->x = info->coords[i].x - info->look_at.x;
	calc->y = info->coords[i].y - info->look_at.y;
	calc->z = info->coords[i].z;
	calc->ry = calc->y * calc->cosx - calc->z * calc->sinx;
	calc->rz = calc->y * calc->sinx + calc->z * calc->cosx;
	calc->y = calc->ry;
	calc->z = calc->rz;
	calc->rx = calc->x * calc->cosy + calc->z * calc->siny;
	calc->rz = calc->z * calc->cosy - calc->x * calc->siny;
	calc->x = calc->rx;
	calc->z = calc->rz;
	calc->rx = calc->x * calc->cosz - calc->y * calc->sinz;
	calc->ry = calc->x * calc->sinz + calc->y * calc->cosz;
	calc->x = calc->rx;
	calc->y = calc->ry;
	calc->x += info->look_at.x;
	calc->y += info->look_at.y;
}

static void	set_iso(t_fdf *info, int i, double first, double second)
{
	info->coords[i].iso_x = info->zoom.center_x + first * info->zoom.scaling;
	info->coords[i].iso_y = info->zoom.center_y + second * info->zoom.scaling;
}

void	parallel_projection(t_fdf *info, int axis)
{
	t_calc	calc;
	int		i;

	i = 0;
	while (i < info->index)
	{
		calc_init(info, &calc, i);
		if (axis == 0)
		{
			set_iso(info, i, calc.x, calc.y);
		}
		else if (axis == 1)
		{
			set_iso(info, i, calc.x, calc.z);
		}
		else if (axis == 2)
		{
			set_iso(info, i, calc.y, calc.z);
		}
		i++;
	}
}

void	isometric_projection(t_fdf *info)
{
	t_calc	calc;
	int		i;

	i = 0;
	while (i < info->index)
	{
		calc_init(info, &calc, i);
		info->coords[i].iso_x = info->zoom.center_x
			+ ((calc.x - calc.y) * cos(PI / 6) * info->zoom.scaling);
		info->coords[i].iso_y = info->zoom.center_y
			- (calc.z * sin(PI / 6) * info->zoom.scaling)
			+ ((calc.x + calc.y) * sin(PI / 6) * info->zoom.scaling);
		i++;
	}
}
