/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:46 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (src_len >= size)
		len = size - 1;
	else
		len = src_len;
	if (size > 0)
	{
		ft_memcpy(dest, src, len);
		dest[len] = '\0';
	}
	return (src_len);
}

/*DESCRIPTION
        The strlcpy() function copies up to size - 1 characters from the
        NUL-terminated string src to dst, NUL-terminating the result.
        Note that a byte for the NUL terminator should be included in size.
        Also note that strlcpy() only operates on true C strings, which means
        src must be NUL-terminated.

RETURN VALUE
        The strlcpy() function returns the total length of the string it tried
        to create, which means the length of src.
-------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h> // For comparison with the standard strlcpy

int main() {
    // Test case 1: Copying a string with enough space
    char dest1[20];
    char src1[] = "Hello, World!";
    size_t size1 = 20;
    size_t result1 = ft_strlcpy(dest1, src1, size1);
    printf("Test case 1: ft_strlcpy(dest, \"%s\", %zu) = \"%s\", Length:
		%zu\n", src1, size1, dest1, result1);

    // Test case 2: Copying a string with limited space
    char dest2[10];
    char src2[] = "Limited";
    size_t size2 = 10;
    size_t result2 = ft_strlcpy(dest2, src2, size2);
    printf("Test case 2: ft_strlcpy(dest, \"%s\", %zu) = \"%s\", Length:
		%zu\n", src2, size2, dest2, result2);

    // Test case 3: Comparison with standard strlcpy
    char dest3[30];
    char src3[] = "Comparison Test";
    size_t size3 = 30;

    // Using ft_strlcpy
    size_t result3 = ft_strlcpy(dest3, src3, size3);
    printf("Test case 3 (ft_strlcpy): \"%s\", Length:
		%zu\n", dest3, result3);

    // Using standard strlcpy
    char dest3_std[30];
    size_t result3_std = strlcpy(dest3_std, src3, size3);
    printf("Test case 3 (strlcpy): \"%s\", Length:
		%zu\n", dest3_std, result3_std);

    return 0;
}
*/