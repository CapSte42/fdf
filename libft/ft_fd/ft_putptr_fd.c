/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:05:56 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_fd(uintptr_t ptr, int fd)
{
	int		print_length;
	char	*base;

	print_length = 0;
	base = "0123456789abcdef";
	if (ptr == 0)
	{
		print_length += ft_putstr_fd("(nil)", fd);
	}
	else
	{
		print_length += ft_putstr_fd("0x", fd);
		print_length += ft_putnbrbase_wrapper_fd(ptr, base, fd);
	}
	return (print_length);
}
