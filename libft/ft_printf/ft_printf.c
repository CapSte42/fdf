/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:06:24 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_formats(va_list args, const char format, int fd)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_putchar_fd(va_arg(args, int), fd);
	else if (format == 's')
		print_length += ft_putstr_fd(va_arg(args, char *), fd);
	else if (format == 'd' || format == 'i')
		print_length += ft_putnbr_fd(va_arg(args, int), fd);
	else if (format == 'u')
		print_length += ft_putunsigned_fd(va_arg(args, unsigned int), fd);
	else if (format == 'x' || format == 'X')
		print_length += ft_puthex_fd(va_arg(args, unsigned int), format, fd);
	else if (format == 'p')
		print_length += ft_putptr_fd(va_arg(args, uintptr_t), fd);
	else if (format == '%')
		print_length += ft_putchar_fd('%', fd);
	return (print_length);
}

int	ft_printf(int fd, const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	if (!(fd == -1) && !(fd >= FD_MAX))
	{
		if (!str)
			return (-1);
		va_start(args, str);
		while (str && str[i])
		{
			if (str[i] == '%')
			{
				print_length += ft_formats(args, str[i + 1], fd);
				i++;
			}
			else
				print_length += ft_putchar_fd(str[i], fd);
			i++;
		}
		va_end(args);
	}
	return (print_length);
}
