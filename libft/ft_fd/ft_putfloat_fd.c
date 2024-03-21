/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:35:10 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/25 17:21:24 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_int_part(double f, int fd)
{
	char	*int_str;
	int		int_part;
	int		print_length;

	int_part = (int)f;
	print_length = 0;
	int_str = ft_itoa(int_part);
	if (!int_str)
		return (-1);
	print_length = ft_putstr_fd(int_str, fd);
	free(int_str);
	return (print_length);
}

static int	print_decimal_part(double f, int fd)
{
	char	*decimal_str;
	double	decimal_part;
	int		decimal_part_as_int;
	int		print_length;

	decimal_part = f - (int)f;
	decimal_part = decimal_part * 100 + 0.5;
	decimal_part_as_int = (int)decimal_part;
	print_length = 0;
	decimal_str = ft_itoa(decimal_part_as_int);
	if (!decimal_str)
		return (-1);
	print_length += ft_putchar_fd('.', fd);
	print_length += ft_putstr_fd(decimal_str, fd);
	free(decimal_str);
	return (print_length);
}

int	ft_putfloat_fd(float f, int fd)
{
	int	print_length;
	int	int_part;
	int	decimal_part;

	if (fd < 0)
		return (-1);
	print_length = 0;
	if (f < 0)
	{
		print_length += ft_putchar_fd('-', fd);
		f = -f;
	}
	int_part = print_int_part(f, fd);
	decimal_part = print_decimal_part(f, fd);
	if (int_part == -1 || decimal_part == -1)
		return (-1);
	print_length += int_part + decimal_part;
	return (print_length);
}
