/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:18:06 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/11 20:51:13 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <math.h>

# define DEFAULT_WIDTH 1920
# define DEFAULT_HEIGHT 1080

# define BACKGROUND_COLOR 0x00000FF
# define DRAWING_COLOR 0x80FFFFFF

# define PI 3.14159265358979323846

typedef struct s_coords
{
	int					x;
	int					y;
	float				z;
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
}						t_zoom;

typedef struct s_fdf
{
	t_coords			*coords;
	t_zoom				zoom;
	int					x_axis;
	int					y_axis;
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
	int					startColor;
	int					endColor;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					err;
	int					e2;
	int					currentColor;
	int					startR;
	int					startG;
	int					startB;
	int					endR;
	int					endG;
	int					endB;
	int					steps;
	float				colorStepR;
	float				colorStepG;
	float				colorStepB;
	float				currentR;
	float				currentG;
	float				currentB;
}						t_draw;

void		ft_checkfile(char *file, t_fdf *fdf);
t_coords	*ft_read_coordinate(char **all_lines);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		drawline(t_fdf *fdf, t_coords start, t_coords end);
void		print_coords(t_fdf *fdf);

#endif
