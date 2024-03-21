/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arrays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:51:07 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_arrays(void **ar1, void **ar2, void **ar3)
{
	int	flag;

	flag = 0;
	if (ar1)
	{
		flag++;
		free(*ar1);
	}
	if (ar2)
	{
		flag++;
		free(*ar2);
	}
	if (ar3)
	{
		flag++;
		free(*ar3);
	}
	return (flag);
}

// ft_free_arrays((void *)&arr, (void *)&lis, (void *)&prev_ind);