/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:33:27 by smontuor          #+#    #+#             */
/*   Updated: 2024/07/21 08:39:21 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_earth_color(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->index)
	{
		if (fdf->coords[i].z == 0)
			fdf->coords[i].color = 0x00FF00;
		else if (fdf->coords[i].z > 0 && fdf->coords[i].z < fdf->z_max / 5)
			fdf->coords[i].color = 0x8B4513;
		else if (fdf->coords[i].z > fdf->z_max / 5
			&& fdf->coords[i].z < fdf->z_max / 2)
			fdf->coords[i].color = 0x808080;
		else if (fdf->coords[i].z > fdf->z_max / 2)
			fdf->coords[i].color = 0xFFFFFF;
		else if (fdf->coords[i].z < 0)
			fdf->coords[i].color = 0x0000FF;
		i++;
	}
}

void	change_stroboscope_color(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->index)
	{
		fdf->coords[i].color = rand() % 0xFFFFFF;
		i++;
	}
}

void	change_shadowed_color(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->index)
	{
		if (fdf->coords[i].z == 0)
			fdf->coords[i].color = 0x000000;
		else if (fdf->coords[i].z > 0 && fdf->coords[i].z < fdf->z_max / 5)
			fdf->coords[i].color = 0x808080;
		else if (fdf->coords[i].z > fdf->z_max / 5
			&& fdf->coords[i].z < fdf->z_max / 2)
			fdf->coords[i].color = 0xC0C0C0;
		else if (fdf->coords[i].z > fdf->z_max / 2)
			fdf->coords[i].color = 0xFFFFFF;
		else if (fdf->coords[i].z < 0)
			fdf->coords[i].color = 0x000000;
		i++;
	}
}

void	reset_colors(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->index)
	{
		fdf->coords[i].color = fdf->coords[i].original_color;
		i++;
	}
}
