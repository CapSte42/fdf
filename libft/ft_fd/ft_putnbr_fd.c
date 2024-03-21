/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:05:39 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_fd(int fd)
{
	if (fd < 0)
	{
		return (-1);
	}
	return (1);
}

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		printed_length;

	printed_length = 0;
	if (ft_check_fd(fd) == -1)
		return (0);
	if (n == INT_MIN)
	{
		printed_length += ft_putstr_fd("-2147483648", fd);
		return (printed_length);
	}
	if (n < 0)
	{
		printed_length += ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		printed_length += ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	printed_length += ft_putchar_fd(c, fd);
	return (printed_length);
}

/*Parameters
	n: The integer to output.
	fd: The file descriptor on which to write.

Return value
	None
	
External functs
	write
	
Description
	Outputs the integer ’n’ to the given file
	descriptor.*/