/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:08:27 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest == NULL || src == NULL || n == 0)
		return (dest);
	if (s < d)
		while (n--)
			d[n] = s[n];
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*DESCRIPTION
       The  memmove()  function  copies n bytes from memory area src to
       memory area dest.  The memory areas may overlap:  copying  takes
       place  as though the bytes in src are first copied into a tempo‐
       rary array that does not overlap src or dest, and the bytes  are
       then copied from the temporary array to dest.

RETURN VALUE
       The memmove() function returns a pointer to dest.
-------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h> // For comparison with the standard memmove

int main() {
    // Test case 1: Copying from source to destination
    char src1[] = "Source String";
    char dest1[20];
    size_t len1 = 14;
    ft_memmove(dest1, src1, len1);
    printf("Test case 1: ft_memmove(\"%s\", \"%s\", %zu) =
	 \"%s\"\n", dest1, src1, len1, dest1);

    // Test case 2: Copying from destination to source (overlapping)
    char str2[] = "Overlapping Test";
    size_t len2 = 10;
    memmove(str2 + 3, str2, len2);
    printf("Test case 2: ft_memmove(\"%s\") = \"%s\"\n", str2, str2 + 3);

    // Test case 3: Comparison with standard memmove
    char src3[] = "Comparison Test";
    char dest3[20];
    size_t len3 = 15;

    // Using ft_memmove
    ft_memmove(dest3, src3, len3);
    printf("Test case 3 (ft_memmove): \"%s\"\n", dest3);

    // Using standard memmove
    char dest3_std[20];
    memmove(dest3_std, src3, len3);
    printf("Test case 3 (memmove): \"%s\"\n", dest3_std);

    return 0;
}
*/