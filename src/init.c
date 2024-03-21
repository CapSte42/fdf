/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:09:11 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/29 14:06:15 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_is_zero(t_fdf *info)
{
	int	i;

	i = 0;
	while (i < info->index)
	{
		if (info->coords[i].z == 0)
			info->coords[i].is_zero = 1;
		else
			info->coords[i].is_zero = 0;
		i++;
	}
}

int	get_and_set_parallel_axis(t_fdf *fdf, int flag)
{
	static int	i;
	static int	f;

	if (flag == 0 && f != 0)
		i++;
	f++;
	if (i == 3)
	{
		fdf->is_right_button_pressed = 0;
		f = 0;
		i = 0;
	}
	return (i);
}

void	go_parallel(t_fdf *fdf)
{
	int	i;

	i = get_and_set_parallel_axis(fdf, 1);
	clear_image(fdf);
	parallel_projection(fdf, i);
	deploy_map(fdf);
	my_mlx_put_image_to_window(fdf, 0);
}
