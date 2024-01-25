/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:23 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

/*DESCRIPTION
       The  strchr()  function returns a pointer to the first occurrence of
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
#include <string.h> // For comparison with the standard strchr

int main() {
    // Test case 1: Character is found in the string
    char str1[] = "Hello, World!";
    char searchChar1 = 'o';
    char *result1 = ft_strchr(str1, searchChar1);
    printf("Test case 1: ft_strchr(\"%s\", '%c') =
		\"%s\"\n", str1, searchChar1, result1);

    // Test case 2: Character is not found in the string
    char str2[] = "Programming";
    char searchChar2 = 'z';
    char *result2 = ft_strchr(str2, searchChar2);
    printf("Test case 2: ft_strchr(\"%s\", '%c') =
		\"%s\"\n", str2, searchChar2, result2);

    // Test case 3: Character is the null terminator
    char str3[] = "Test String";
    char searchChar3 = '\0';
    char *result3 = ft_strchr(str3, searchChar3);
    printf("Test case 3: ft_strchr(\"%s\", '\\0') =
		\"%s\"\n", str3, result3);

    // Test case 4: Comparison with standard strchr
    char str4[] = "Comparison Test";
    char searchChar4 = 's';

    // Using ft_strchr
    char *result4 = ft_strchr(str4, searchChar4);
    printf("Test case 4 (ft_strchr): \"%s\"\n", result4);

    // Using standard strchr
    char *result4_std = strchr(str4, searchChar4);
    printf("Test case 4 (strchr): \"%s\"\n", result4_std);

    return 0;
}
*/