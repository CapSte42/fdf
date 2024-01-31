/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:20:50 by smontuor          #+#    #+#             */
/*   Updated: 2024/01/31 22:43:47 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_n_array(va_list *args, int c_array)
{
	int		i;
	void	**ptr;

	i = 0;
	while (i < c_array)
	{
		ptr = va_arg(*args, void **);
		if (ptr != NULL && *ptr != NULL)
		{
			free(*ptr);
			*ptr = NULL;
		}
		i++;
	}
}

static void	ft_free_n_matrix(va_list *args, int c_matrix)
{
	int		i;
	int		j;
	void	***array_ptr;

	i = 0;
	while (i < c_matrix)
	{
		array_ptr = va_arg(*args, void ***);
		if (array_ptr != NULL && *array_ptr != NULL)
		{
			j = 0;
			while ((*array_ptr)[j] != NULL)
			{
				free((*array_ptr)[j]);
				j++;
			}
			free(*array_ptr);
			*array_ptr = NULL;
		}
		i++;
	}
}

void	ft_free_n(int c_array, int c_matrix, ...)
{
	va_list	args;

	va_start(args, c_matrix);
	if (c_array > 0)
		ft_free_n_array(&args, c_array);
	if (c_matrix > 0)
		ft_free_n_matrix(&args, c_matrix);
	va_end(args);
}

/* ESEMPI D'USO

 */