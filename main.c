/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:59:24 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/01 21:57:12 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_coordinates	*coordinates;
	char			**all_lines;

	if (ac != 2)
		ft_exit_error("Yeah. Whatever.");
	all_lines = ft_checkfile(av[1]);
	//coordinates = ft_read_coordinate(all_lines);

	ft_free_n(0, 1, &all_lines);
}

