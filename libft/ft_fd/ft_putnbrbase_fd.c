/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:05:48 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkerror(char *str)
{
	int	i;
	int	j;
	int	x;

	x = ft_strlen(str);
	i = 0;
	if (str[0] == '\0' || x == 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] == 127 || str[i] == 43 || str[i] == 45)
			return (0);
		j = i + 1;
		while (j < x)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_putnbrbase_fd(uintptr_t nbr, char *base, int base_len, int fd)
{
	int	printed_chars;

	printed_chars = 0;
	if (nbr < (unsigned int)base_len)
	{
		ft_putchar_fd(base[nbr], fd);
		printed_chars++;
	}
	else
	{
		printed_chars += ft_putnbrbase_fd(nbr / base_len, base, base_len, fd);
		ft_putchar_fd(base[nbr % base_len], fd);
		printed_chars++;
	}
	return (printed_chars);
}

int	ft_putnbrbase_wrapper_fd(uintptr_t nbr, char *base, int fd)
{
	int	base_len;
	int	error;
	int	printed_length;

	base_len = ft_strlen(base);
	error = checkerror(base);
	if (error == 1)
	{
		printed_length = ft_putnbrbase_fd(nbr, base, base_len, fd);
		return (printed_length);
	}
	return (0);
}
