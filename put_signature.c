/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_signature.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:12:56 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/12 18:13:37 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_signature(t_fdf *fdf)
{
	char	*to_write;

	to_write = "by smontuor@42";
	mlx_string_put(fdf->mlx, fdf->mlx_win, 130, 920, 0x7cfc00, to_write);
}
