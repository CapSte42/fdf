/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:08:23 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*buff1;
	const unsigned char	*buff2;

	if (!(dest) && !(src))
		return (dest);
	buff1 = (unsigned char *)dest;
	buff2 = (const unsigned char *)src;
	if (dest < src && src < dest + n)
		return (ft_memmove(dest, src, n));
	while (n--)
		*buff1++ = *buff2++;
	return (dest);
}

/*DESCRIPTION
       The  memcpy()  function  copies  n bytes from memory area src to
       memory area dest.  The memory areas must not overlap.  Use  mem‐
       move(3) if the memory areas do overlap.

RETURN VALUE
       The memcpy() function returns a pointer to dest.
-----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h> // For comparison with the standard memcpy

int main() {

    char src1[] = "Source String";
    char dest1[14];
    size_t len1 = 15;
    ft_memcpy(dest1, src1, len1);
    printf
	("Test case:ft_memcpy(\"%s\",\"%s\",%zu)=\"%s\"\n",dest1,src1,len1,dest1)

    return 0;
}
*/