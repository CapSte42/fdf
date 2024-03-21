/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_related.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:03:28 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/26 22:51:50 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_sphere(t_fdf *info, int i, t_sphere *sphere)
{
	sphere->r = R_BASE + (info->coords[i].z * Z_SCALE);
	sphere->normale_x
		= ((info->coords[i].x / (double)info->x_axis) * 2 * PI) - PI;
	sphere->normale_y
		= ((info->coords[i].y / (double)info->y_axis) * PI) - PI / 2;
	sphere->normale_y = fmax(-PI / 2, fmin(PI / 2, sphere->normale_y));
	sphere->lambda = sphere->normale_x;
	sphere->phi = sphere->normale_y;
}

static void	calculate_spherical_coordinates(t_sphere *sphere)
{
	sphere->x_prime = sphere->r * cos(sphere->phi) * cos(sphere->lambda);
	sphere->y_prime = sphere->r * cos(sphere->phi) * sin(sphere->lambda);
	sphere->z_prime = sphere->r * sin(sphere->phi);
}

static void	make_it_move(t_sphere *sphere)
{
	double	x_temp;
	double	y_temp;
	double	z_temp;

	y_temp = sphere->y_prime
		* cos(sphere->theta_x) - sphere->z_prime * sin(sphere->theta_x);
	z_temp = sphere->y_prime
		* sin(sphere->theta_x) + sphere->z_prime * cos(sphere->theta_x);
	sphere->y_prime = y_temp;
	sphere->z_prime = z_temp;
	x_temp = sphere->x_prime
		* cos(sphere->theta_y) + sphere->z_prime * sin(sphere->theta_y);
	z_temp = -sphere->x_prime
		* sin(sphere->theta_y) + sphere->z_prime * cos(sphere->theta_y);
	sphere->x_prime = x_temp;
	sphere->z_prime = z_temp;
	x_temp = sphere->x_prime
		* cos(sphere->theta_z) - sphere->y_prime * sin(sphere->theta_z);
	y_temp = sphere->x_prime
		* sin(sphere->theta_z) + sphere->y_prime * cos(sphere->theta_z);
	sphere->x_prime = x_temp;
	sphere->y_prime = y_temp;
}

static void	flat_to_sphere(t_fdf *info, int i, double *z)
{
	t_sphere	sphere;

	init_sphere(info, i, &sphere);
	sphere.theta_x = info->rot_x * (PI / 180.0);
	sphere.theta_y = info->rot_y * (PI / 180.0);
	sphere.theta_z = info->rot_z * (PI / 180.0);
	calculate_spherical_coordinates(&sphere);
	make_it_move(&sphere);
	info->coords[i].iso_x = sphere.x_prime;
	info->coords[i].iso_y = sphere.y_prime;
	*z = sphere.z_prime;
}

void	apply_flat_to_sphere(t_fdf *info)
{
	double	z;
	int		i;

	i = 0;
	while (i < info->index)
	{
		flat_to_sphere(info, i, &z);
		if (z >= -(R_BASE / 2) * 0.5)
		{
			info->coords[i].is_visible = 1;
			info->coords[i].iso_x
				= info->coords[i].iso_x
				* info->zoom.scaling + DEFAULT_WIDTH / 2;
			info->coords[i].iso_y
				= info->coords[i].iso_y
				* info->zoom.scaling + DEFAULT_HEIGHT / 2;
			info->coords[i].iso_z = z;
		}
		else
			info->coords[i].is_visible = 0;
		i++;
	}
	deploy_sphere(info);
}
