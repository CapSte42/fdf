/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_related.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:33:43 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/26 18:08:52 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_zoom_and_center(t_fdf *fdf)
{
	fdf->zoom.scaling
		= (fmin(DEFAULT_WIDTH / fdf->x_axis, DEFAULT_HEIGHT / fdf->y_axis)) / 2;
	fdf->zoom.center_x = DEFAULT_WIDTH / 2;
	fdf->zoom.center_y
		= (DEFAULT_HEIGHT / 2) - (fdf->y_axis * fdf->zoom.scaling / 2);
	fdf->rot_x = 0;
	fdf->rot_y = 0;
	fdf->rot_z = 0;
	fdf->distance = 200;
	fdf->depth = 1;
	reset_z(fdf);
}
