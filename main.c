/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:59:24 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/06 10:48:33 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_coords	*coords;
	int	tot_punti;

	if (ac != 2)
		ft_exit_error("Yeah. Whatever.");
	tot_punti = ft_checkfile(av[1], &coords);

	for(int i = 0; i < tot_punti; i++)
	{
		printf("coords.x = %f , coords.y = %f , coords.z = %f , color = %ld\n", coords[i].x, coords[i].y, coords[i].z, coords[i].color);
	}

	ft_free_n(1, 0, &coords);
}

