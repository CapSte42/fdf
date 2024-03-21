/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:31:07 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/28 18:11:27 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_coords
{
	double					x;
	double					y;
	double					z;
	int						is_zero;
	double					iso_x;
	double					iso_y;
	double					iso_z;
	int						is_visible;
	unsigned long int		tmp_color;
	unsigned long int		color;
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
}						t_zoom;

typedef struct s_fdf
{
	t_coords			*coords;
	t_coords			look_at;
	t_zoom				zoom;
	double				depth;
	double				distance;
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
	int					is_left_button_pressed;
	int					is_right_button_pressed;
	int					is_sphere;
	int					initial_x;
	int					initial_y;
	int					keep_parallel;
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
	double				color_step_r;
	double				color_step_g;
	double				color_step_b;
	double				current_r;
	double				current_g;
	double				current_b;
}						t_draw;

typedef struct s_calc
{
	double				x;
	double				y;
	double				z;
	double				rx;
	double				ry;
	double				rz;
	double				cosx;
	double				sinx;
	double				cosy;
	double				siny;
	double				cosz;
	double				sinz;
}						t_calc;

typedef struct s_sphere
{
	double				lambda;
	double				phi;
	double				normale_x;
	double				normale_y;
	double				r;
	double				theta_x;
	double				theta_y;
	double				theta_z;
	double				x_prime;
	double				y_prime;
	double				z_prime;
}						t_sphere;

#endif
