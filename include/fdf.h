/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:18:06 by smontuor          #+#    #+#             */
/*   Updated: 2024/01/23 07:40:34 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define BACKGROUND_COLOR 0x00000FF
# define DRAWING_COLOR 0xFFFFFFFF

typedef struct s_coordinate
{
	float			x;
	float			y;
	float			z;
}					t_coordinates;

typedef struct	s_data {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

void	ft_checkfile(char *file);

#endif