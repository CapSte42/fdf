/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:20:07 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/12 08:56:11 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_coords(t_fdf *fdf)
{
	int	i;

	i = 0;
	ft_printf("index -> point (x, y, z) = color\n");
	while (i < fdf->index)
	{
		ft_printf("%d -> (%d, %d, %f) = %u\n", i,
			fdf->coords[i].x, fdf->coords[i].y, fdf->coords[i].z,
			fdf->coords[i].color);
		i++;
	}
	ft_printf("x_axis = %d , y_axis = %d , index = %d\n",
		fdf->y_axis, fdf->x_axis, fdf->index);
}

void	print_iso_coords(t_fdf *fdf)
{
	int	i;

	i = 0;
	ft_printf("index -> point (x, y, z) = color\n");
	while (i < fdf->index)
	{
		ft_printf("%d -> (%d, %d, %f) = %u\n", i,
			fdf->coords[i].iso_x, fdf->coords[i].iso_y, fdf->coords[i].z,
			fdf->coords[i].color);
		i++;
	}
	ft_printf("x_axis = %d , y_axis = %d , index = %d\n",
		fdf->y_axis, fdf->x_axis, fdf->index);
}
