/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:37 by smontuor          #+#    #+#             */
/*   Updated: 2024/01/31 22:12:52 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freejoin(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)malloc(len_s1 + len_s2 + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, len_s1 + 1);
	ft_strlcat(result, s2, len_s1 + len_s2 + 1);
	free((char *)s1);
	return (result);
}

/*Parameters
	s1: The prefix string.
	s2: The suffix string.
Return value
	The new string.
	NULL if the allocation fails.
External functs
	malloc
Description
	Allocates (with malloc(3)) and returns a new
	string, which is the result of the concatenation
	of ’s1’ and ’s2’.
-------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h> // For comparison with the standard strjoin

int main() {
    // Test case 1: Concatenating two strings
    char str1[] = "Hello, ";
    char str2[] = "World!";
    char *result1 = ft_strjoin(str1, str2);
    printf("Test case 1: ft_strjoin(\"%s\", \"%s\") =
		\"%s\"\n", str1, str2, result1);
    free(result1);

    // Test case 2: Concatenating an empty string
    char str3[] = "";
    char str4[] = "Test";
    char *result2 = ft_strjoin(str3, str4);
    printf("Test case 2: ft_strjoin(\"%s\", \"%s\") =
		\"%s\"\n", str3, str4, result2);
    free(result2);

    // Test case 3: Concatenating strings with spaces
    char str5[] = "Spaces";
    char str6[] = "Between";
    char *result3 = ft_strjoin(str5, str6);
    printf("Test case 3: ft_strjoin(\"%s\", \"%s\") =
		\"%s\"\n", str5, str6, result3);
    free(result3);

    // Test case 4: Comparison with standard strjoin
    char str7[] = "Comparison ";
    char str8[] = "Test";

    // Using ft_strjoin
    char *result4 = ft_strjoin(str7, str8);
    printf("Test case 4 (ft_strjoin): \"%s\"\n", result4);
    free(result4);

    // Using standard strjoin
    char str9[30] = "Comparison ";
    strcat(str9, str8);
    printf("Test case 4 (strcat): \"%s\"\n", str9);

    return 0;
}
*/
