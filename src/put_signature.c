/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_signature.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:12:56 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/26 00:47:29 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_signature(t_fdf *fdf)
{
	char	*to_write;

	to_write = "by smontuor@42Firenze";
	mlx_set_font(fdf->mlx, fdf->mlx_win,
		"-misc-fixed-bold-r-normal--13-100-100-100-c-70-iso8859-1");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 1700, 920, 0x7cfc00, to_write);
}
