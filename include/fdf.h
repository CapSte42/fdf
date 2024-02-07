/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:18:06 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/07 14:32:13 by smontuor         ###   ########.fr       */
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
# define DRAWING_COLOR 0xFFFFFFFF

# define PI 3.14159265358979323846

typedef struct s_coords
{
	int					x;
	int					y;
	float				z;
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

typedef struct s_fdf
{
	t_coords			*coords;
	int					tot_riga;
	int					tot_colonna;
	int					tot_punti;
	char				*name;
	void				*mlx;
	void				*mlx_win;
	t_data				img;
}						t_fdf;

void		ft_checkfile(char *file, t_fdf *fdf);
t_coords	*ft_read_coordinate(char **all_lines);
#endif
