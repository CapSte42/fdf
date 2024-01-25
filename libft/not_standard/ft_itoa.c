/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:08:52 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;
	int		sign;

	num = n;
	sign = 1;
	if (num < 0)
	{
		sign = -1;
		num = -num;
	}
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = '0' + (num % 10);
		num /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

/*Parameters
	n: the integer to convert.
Return value
	The string representing the integer.
	NULL if the allocation fails.
External functs
	malloc
Description
	Allocates (with malloc(3)) and returns a string
	representing the integer received as an argument.
	Negative numbers must be handled.
-------------------------------------------------------------------------------
#include <stdio.h>

int main()
{
    int num = -12345;
    char *str = ft_itoa(num);
    if (str != NULL)
    {
        printf("La rappresentazione stringa del numero %d è: %s\n", num, str);
        free(str);
    }
    else
    {
        printf("Errore di allocazione della memoria.\n");
    }
    return 0;
}
*/