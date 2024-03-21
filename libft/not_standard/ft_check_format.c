/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:18:58 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/11 13:34:50 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_format(const char *file, const char *format)
{
	char	*dot;

	dot = ft_strrchr(file, '.');
	if (!dot || dot == file)
		ft_exit_error("Wrong file format.");
	if (!ft_strncmp(dot, format, 5) == 0)
		ft_exit_error("Wrong file format.");
}
