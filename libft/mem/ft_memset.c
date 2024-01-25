/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:08:32 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*buffer;

	buffer = (unsigned char *)s;
	while (n > 0)
	{
		*buffer = (unsigned char)c;
		buffer++;
		n--;
	}
	return (s);
}

/*DESCRIPTION
       The  memset()  function  fills  the first n bytes of the memory area
       pointed to by s with the constant byte c.

RETURN VALUE
       The memset() function returns a pointer to the memory area s.
-------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h> // For comparison with the standard memset
#include "libft.h"

int main() {
    // Test case 1: Setting a portion of an array to a specific value
    char str1[] = "Hello, World!";
    size_t len1 = 5;
    ft_memset(str1, 'X', len1);
    printf("Test case 1: ft_memset(\"%s\", 'X', %zu) =
		\"%s\"\n", str1, len1, str1);

    // Test case 2: Setting the entire array to a specific value
    char str2[] = "Goodbye";
    size_t len2 = 8;
    ft_memset(str2, 'A', len2);
    printf("Test case 2: ft_memset(\"%s\", 'A', %zu) =
		\"%s\"\n", str2, len2, str2);

    // Test case 3: Comparison with standard memset
    char str3[] = "Comparison Test";
    size_t len3 = 15;

    // Using ft_memset
    ft_memset(str3, 'Z', len3);
    printf("Test case 3 (ft_memset): \"%s\"\n", str3);

    // Using standard memset
    char str3_std[] = "Comparison Test";
    memset(str3_std, 'Z', len3);
    printf("Test case 3 (memset): \"%s\"\n", str3_std);

    return 0;
}
*/