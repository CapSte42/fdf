/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_related.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:33:53 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/11 21:59:10 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	int_to_isometric_pixel(t_fdf *info)
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

void int_to_perspective_projection(t_fdf *info) {
    int i;
    float perspective_scale;
    float distance_to_camera = 500.0;
    float depth_factor = 2.0;

    i = 0;
    while (i < info->index) {

        perspective_scale = distance_to_camera / (distance_to_camera + (info->coords[i].z * depth_factor) * info->zoom.scaling);

        info->coords[i].iso_x = info->zoom.center_x + ((info->coords[i].x - info->coords[i].y) * cos(PI / 6) * info->zoom.scaling * perspective_scale);
        info->coords[i].iso_y = info->zoom.center_y + ((info->coords[i].x + info->coords[i].y) * sin(PI / 6) * info->zoom.scaling * perspective_scale) - (info->coords[i].z * sin(PI / 6) * info->zoom.scaling * perspective_scale);

        i++;
    }
}