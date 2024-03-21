/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_related.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:38:22 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/29 15:13:36 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < DEFAULT_HEIGHT)
	{
		j = 0;
		while (j < DEFAULT_WIDTH)
		{
			my_mlx_pixel_put(&fdf->img, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

void	update_z(t_fdf *info, int flag)
{
	int	i;

	i = 0;
	while (i < info->index)
	{
		if (info->coords[i].is_zero == 0)
		{
			info->coords[i].z += flag;
		}
		i++;
	}
	info->z_mod += flag;
}

void	reset_z(t_fdf *info)
{
	int	i;

	i = 0;
	while (i < info->index)
	{
		if (info->coords[i].is_zero == 0)
		{
			info->coords[i].z -= info->z_mod;
		}
		i++;
	}
	info->z_mod = 0;
}

void	calculate_look_at_for_height_map(t_fdf *info)
{
	info->look_at.x = (info->x_axis - 1) / 2.0;
	info->look_at.y = (info->y_axis - 1) / 2.0;
	info->look_at.z = (info->z_min + info->z_max) / 2.0;
}
