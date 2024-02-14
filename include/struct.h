/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:31:07 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/14 01:02:31 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_coords
{
	float					x;
	float					y;
	float				z;
	int					is_zero;
	float				iso_x;
	float				iso_y;
	unsigned long int	color;
}						t_coords;

typedef struct s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

typedef struct s_zoom
{
	int					center_x;
	int					center_y;
	int					scaling;
	int					angle;
}						t_zoom;

typedef struct s_fdf
{
	t_coords			*coords;
	t_zoom				zoom;
	double				rot_x;
	double				rot_y;
	double				rot_z;
	int					x_axis;
	int					y_axis;
	int					z_max;
	int					z_min;
	int					z_mod;
	int					index;
	char				*name;
	void				*mlx;
	void				*mlx_win;
	t_data				img;
}						t_fdf;

typedef struct s_draw
{
	int					x0;
	int					y0;
	int					x1;
	int					y1;
	int					start_color;
	int					end_color;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					err;
	int					e2;
	int					current_color;
	int					start_r;
	int					start_g;
	int					start_b;
	int					end_r;
	int					end_g;
	int					end_b;
	int					steps;
	float				color_step_r;
	float				color_step_g;
	float				color_step_b;
	float				current_r;
	float				current_g;
	float				current_b;
}						t_draw;

#endif
