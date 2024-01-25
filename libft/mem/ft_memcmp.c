/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:08:18 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*buff1;
	unsigned char	*buff2;
	int				return_value;

	buff1 = (unsigned char *)s1;
	buff2 = (unsigned char *)s2;
	return_value = 0;
	if (s1 == s2)
		return (return_value);
	while (n)
	{
		if (*buff1 != *buff2)
		{
			if (*buff1 > *buff2)
				return_value = 1;
			else
				return_value = -1;
			break ;
		}
		n--;
		buff1++;
		buff2++;
	}
	return (return_value);
}

/*DESCRIPTION
       The  memcmp() function compares the first n bytes (each interpreted as
       unsigned char) of the memory areas s1 and s2.

RETURN VALUE
       The memcmp() function returns an  integer  less  than,  equal  to,  or
       greater  than  zero if the first n bytes of s1 is found, respectively,
       to be less than, to match, or be greater than the first n bytes of s2.

       For a nonzero return value, the sign is determined by the sign of  the
       difference  between  the  first pair of bytes (interpreted as unsigned
       char) that differ in s1 and s2.

       If n is zero, the return value is zero.
-------------------------------------------------------------------------------
#include <stdio.h>

int main() {
    // Test case 1: Strings are equal
    char str1[] = "Hello";
    char str2[] = "Hello";
    size_t len1 = 5;
    int result1 = ft_memcmp(str1, str2, len1);
    printf("Test case 1: ft_memcmp(\"%s\", \"%s\", %zu) =
		%d\n", str1, str2, len1, result1);

    // Test case 2: Strings are different
    char str3[] = "Hello";
    char str4[] = "World";
    size_t len2 = 5;
    int result2 = ft_memcmp(str3, str4, len2);
    printf("Test case 2: ft_memcmp(\"%s\", \"%s\", %zu) =
		%d\n", str3, str4, len2, result2);

    // Test case 3: Compare only the first 3 characters
    char str5[] = "ABC";
    char str6[] = "DEF";
    size_t len3 = 3;
    int result3 = ft_memcmp(str5, str6, len3);
    printf("Test case 3: ft_memcmp(\"%s\", \"%s\", %zu) =
		%d\n", str5, str6, len3, result3);

    return 0;
}
*/