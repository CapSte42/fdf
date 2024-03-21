/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:01 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*substr;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	sub_len = s_len - start;
	if (len < sub_len)
		sub_len = len;
	substr = (char *)malloc(sizeof(char) * (sub_len + 1));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, sub_len + 1);
	return (substr);
}

/*Parameters 
	s:		The string from which to create the substring.
	start: 	The start index of the substring in the
			string ’s’.
	len: 	The maximum length of the substring.
	
Return value
	The substring.
	NULL if the allocation fails.

External functs
	malloc

Description
	Allocates (with malloc(3)) and returns a substring
	from the string ’s’.
	The substring begins at index ’start’ and is of
	maximum size ’len’.
-------------------------------------------------------------------------------
include <stdio.h>
#include <string.h> // For comparison with the standard strncpy

int main() {
    // Test case 1: Creating a substring from the middle of a string
    char str1[] = "Hello, World!";
    unsigned int start1 = 7;
    size_t len1 = 5;
    char *result1 = ft_substr(str1, start1, len1);
    printf("Test case 1: ft_substr(\"%s\", %u, %zu) = \"%s\"\n", str1,
		start1, len1, result1);
    free(result1); // Remember to free allocated memory

    // Test case 2: Creating a substring from the beginning of a string
    char str2[] = "Hello, World!";
    unsigned int start2 = 0;
    size_t len2 = 5;
    char *result2 = ft_substr(str2, start2, len2);
    printf("Test case 2: ft_substr(\"%s\", %u, %zu) = \"%s\"\n",
		str2, start2, len2, result2);
    free(result2); // Remember to free allocated memory

    // Test case 3: Creating a substring with length exceeding
	//	the remaining string
    char str3[] = "Hello, World!";
    unsigned int start3 = 6;
    size_t len3 = 20;
    char *result3 = ft_substr(str3, start3, len3);
    printf("Test case 3: ft_substr(\"%s\", %u, %zu) = \"%s\"\n",
		str3, start3, len3, result3);
    free(result3); // Remember to free allocated memory

    // Test case 4: Creating a substring with a null string
    char *str4 = NULL;
    unsigned int start4 = 0;
    size_t len4 = 5;
    char *result4 = ft_substr(str4, start4, len4);
    printf("Test case 4: ft_substr(NULL, %u, %zu) =
		\"%s\"\n", start4, len4, result4);
    free(result4); // Remember to free allocated memory

    // Test case 5: Comparison with standard strncpy
    char str5[] = "Hello, World!";
    unsigned int start5 = 7;
    size_t len5 = 5;

    // Using ft_substr
    char *result5 = ft_substr(str5, start5, len5);
    printf("Test case 5 (ft_substr): \"%s\"\n", result5);
    free(result5); // Remember to free allocated memory

    // Using standard strncpy
    char result5_std[6]; // Assuming a fixed size for simplicity
    strncpy(result5_std, str5 + start5, len5);
    result5_std[len5] = '\0';
    printf("Test case 5 (strncpy): \"%s\"\n", result5_std);

    return 0;
}
*/