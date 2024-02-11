/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_related.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:33:53 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/11 21:36:44 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void int_to_isometric_pixel(t_fdf *info)
{
	int	i;

	i = 0;
	while (i < info->index)
	{
		info->coords[i].iso_x
			= (info->zoom.center_x)
			+ ((info->coords[i].x
			- info->coords[i].y)
			* cos(PI / 6)
			* info->zoom.scaling);
		info->coords[i].iso_y
		= (info->zoom.center_y)
			- (info->coords[i].z
			* sin(PI / 6)
			* info->zoom.scaling)
			+ ((info->coords[i].x
			+ info->coords[i].y)
			* sin(PI / 6)
			* info->zoom.scaling);
		i++;
	}
}
