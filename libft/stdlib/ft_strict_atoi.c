/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strict_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:12 by smontuor          #+#    #+#             */
/*   Updated: 2024/01/31 22:09:03 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ispositive(int c)
{
	if (c == '+')
		return (1);
	return (-1);
}

static intmax_t	ft_mount_num(const char *nptr, int *error)
{
	intmax_t	i;
	size_t		z;
	size_t		sign;

	i = 0;
	z = 0;
	sign = 1;
	while (ft_isspace(nptr[z]))
		z++;
	if (nptr[z] == '\0')
	{
		*error = 1;
		return (0);
	}
	if (nptr[z] == '-' || nptr[z] == '+')
	{
		sign = ft_ispositive(nptr[z]);
		z++;
	}
	while (nptr[z] && nptr[z] >= '0' && nptr[z] <= '9')
	{
		i = i * 10 + nptr[z] - '0';
		z++;
	}
	return (i * sign);
}

int	ft_strict_atoi(const char *nptr, int *error)
{
	intmax_t	num;

	*error = 0;
	num = ft_mount_num(nptr, error);
	if (*error == 1)
		return (0);
	if (num < INT_MIN || num > INT_MAX)
	{
		*error = 1;
		return (0);
	}
	return ((int)num);
}

/*DESCRIPTION
       The  atoi()  function  converts  the  initial  portion of the
       nptring pointed to by nptr to int.
       (...)except that atoi() does not detect errors.

RETURN VALUE
       The converted value.
-------------------------------------------------------------------------------*
#include <stdio.h>

int main() 
{
	int *error = 0;
	
    const char *test_cases[] = 
	{
        "   123",    // Test case with leading spaces
        "-456",      // Test case with negative number
        "+789",      // Test case with positive number
        "   123abc", // Test case with non-numeric characters after the number
        "   abc123", // Test case with non-numeric characters before the number
        "   2147483647", // Maximum positive integer value
        "   -2147483648", // Minimum negative integer value
        "   999999999999999999999999999999999999999999999", // Very large + num
        "   -999999999999999999999999999999999999999999999" // Very large - num
    };

    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); ++i) {
        int result = ft_atoi(test_cases[i], &error);
		if (*error == 1)
			exit (-1);
        printf("Input: \"%s\", Result: %d\n", test_cases[i], result);
    }

    return 0;
}
*/