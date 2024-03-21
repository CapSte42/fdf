/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:10:09 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			last = s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return ((char *)last);
}

/*DESCRIPTION
       The strrchr() function returns a pointer to the last  occurrence  of
       the character c in the string s.

       Here "character" means "byte"; these functions do not work with wide
       or multibyte characters.

RETURN VALUE
       The strchr() and strrchr() functions return a pointer to the matched
       character  or  NULL  if the character is not found.  The terminating
       null byte is considered part of the string, so that if c  is  speci‐
       fied as '\0', these functions return a pointer to the terminator.
-------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h> // For comparison with the standard strrchr

int main() {
    // Test case 1: Finding the last occurrence of a character
    char str1[] = "Hello, World!";
    char c1 = 'o';
    char *result1 = ft_strrchr(str1, c1);
    printf("Test case 1: ft_strrchr(\"%s\", '%c') =
		\"%s\"\n", str1, c1, result1);

    // Test case 2: Finding the last occurrence of a character at the beginning
    char str2[] = "Hello, World!";
    char c2 = 'H';
    char *result2 = ft_strrchr(str2, c2);
    printf("Test case 2: ft_strrchr(\"%s\", '%c') =
		\"%s\"\n", str2, c2, result2);

    // Test case 3: Finding the last occurrence of a character that
	//	doesn't exist
    char str3[] = "Hello, World!";
    char c3 = 'z';
    char *result3 = ft_strrchr(str3, c3);
    printf("Test case 3: ft_strrchr(\"%s\", '%c') =
		\"%s\"\n", str3, c3, result3);

    // Test case 4: Comparison with standard strrchr
    char str4[] = "Hello, World!";
    char c4 = 'o';

    // Using ft_strrchr
    char *result4 = ft_strrchr(str4, c4);
    printf("Test case 4 (ft_strrchr): \"%s\"\n", result4);

    // Using standard strrchr
    char *result4_std = strrchr(str4, c4);
    printf("Test case 4 (strrchr): \"%s\"\n", result4_std);

    return 0;
}
*/