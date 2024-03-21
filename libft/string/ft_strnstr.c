/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:10:04 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_length;

	if (!(*little))
		return ((char *)big);
	little_length = ft_strlen(little);
	if (little_length > len)
		return (NULL);
	i = 0;
	while (big[i] != '\0' && (i + little_length) <= len)
	{
		if (ft_strncmp(big + i, little, little_length) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/*DESCRIPTION
     The strnstr() function locates the first occurrence of the null-termi‐
     nated string little in the string big, where not more than len charac‐
     ters are searched.  Characters that appear after a ‘\0’ character are
     not searched.  Since the strnstr() function is a FreeBSD specific API,
     it should only be used when portability is not a concern.

RETURN VALUES
     If little is an empty string, big is returned; if little occurs
     nowhere in big, NULL is returned; otherwise a pointer to the first
     character of the first occurrence of little is returned.
-------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h> // For comparison with the standard strnstr

int main() {
    // Test case 1: Finding a substring in the middle of a string
    char big1[] = "Hello, World!";
    char little1[] = "el";
    size_t len1 = 13;
    char *result1 = ft_strnstr(big1, little1, len1);
    printf("Test case 1: ft_strnstr(\"%s\", \"%s\", %zu) =\"%s\"\n",
	big1, little1, len1, result1);

    // Test case 2: Finding a substring at the beginning of a string
    char big2[] = "Hello, World!";
    char little2[] = "aaaa";
    size_t len2 = 13;
    char *result2 = ft_strnstr(big2, little2, len2);
    printf("Test case 2: ft_strnstr(\"%s\", \"%s\", %zu) =\"%s\"\n",
	big2, little2, len2, result2);

    // Test case 3: Not finding a substring
    char big3[] = "Hello, World!";
    char little3[] = "aaaa";
    size_t len3 = 13;
    char *result3 = ft_strnstr(big3, little3, len3);
    printf("Test case 3: ft_strnstr(\"%s\", \"%s\", %zu) =\"%s\"\n",
	big3, little3, len3, result3);


    return 0;
}
*/