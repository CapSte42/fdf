/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:42 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	buf_left;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dest_len >= size)
		return (src_len + size);
	buf_left = size - dest_len;
	if (buf_left > src_len)
		buf_left = src_len;
	else
		buf_left -= 1;
	ft_memcpy(dest + dest_len, src, buf_left);
	dest[dest_len + buf_left] = '\0';
	return (dest_len + src_len);
}

/*DESCRIPTION
        The strlcat() function appends the NUL-terminated string src to the end
        of dst. It will append at most size - strlen(dst) - 1 bytes,
        NUL-terminating the result.
        Note that a byte for the NUL terminator should be included in size.
        Also note that strlcat() only operates on true C strings, which means
        src and dst must be NUL-terminated.

RETURN VALUE
        The strlcat() function returns the initial length of dst plus the
        length of src. This is the total length of the string it tried to
        create.
        Note that if strlcat() traverses size characters without finding a NUL,
        the length is considered to be size and dst will not be NUL-terminated.
        This prevents potential security problems.
-------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h> // For comparison with the standard strlcat

int main() {
    // Test case 1: Concatenating two strings with enough space
    char dest1[20] = "Hello, ";
    char src1[] = "World!";
    size_t size1 = 20;
    size_t result1 = ft_strlcat(dest1, src1, size1);
    printf("Test case 1: ft_strlcat(\"%s\", \"%s\", %zu) = \"%s\", Length:
		%zu\n", "Hello, ", "World!", size1, dest1, result1);

    // Test case 2: Concatenating strings with limited space
    char dest2[15] = "Limited ";
    char src2[] = "Space";
    size_t size2 = 15;
    size_t result2 = ft_strlcat(dest2, src2, size2);
    printf("Test case 2: ft_strlcat(\"%s\", \"%s\", %zu) = \"%s\", Length:
		%zu\n", "Limited ", "Space", size2, dest2, result2);

    // Test case 3: Comparison with standard strlcat
    char dest3[30] = "Comparison ";
    char src3[] = "Test";
    size_t size3 = 30;

    // Using ft_strlcat
    size_t result3 = ft_strlcat(dest3, src3, size3);
    printf("Test case 3 (ft_strlcat): \"%s\", Length:
		%zu\n", dest3, result3);

    // Using standard strlcat
    char dest3_std[30] = "Comparison ";
    size_t result3_std = strlcat(dest3_std, src3, size3);
    printf("Test case 3 (strlcat): \"%s\", Length:
		%zu\n", dest3_std, result3_std);

    return 0;
}
*/