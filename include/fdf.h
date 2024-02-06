/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:18:06 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/06 13:37:01 by smontuor         ###   ########.fr       */
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

typedef struct s_coordinate
{
	float			x;
	float			y;
	float			z;
	char*			color;
}					t_coords;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

char			**ft_checkfile(char *file);
t_coords	*ft_read_coordinate(char **all_lines);
#endif
