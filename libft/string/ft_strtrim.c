/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:10:13 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chr_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	s1_len;

	start = 0;
	if (!s1 || s1 == NULL)
		return (NULL);
	if (!(set) || set == NULL)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	while (s1[start] && chr_in_set(s1[start], set))
		start++;
	while (s1_len > start && chr_in_set(s1[s1_len - 1], set))
		s1_len--;
	return (ft_substr(s1, start, s1_len - start));
}

/*Parameters
	s1: The string to be trimmed.
	set: The reference set of characters to trim.

Return value
	The trimmed string.
	NULL if the allocation fails.

External functs
	malloc

Description
	Allocates (with malloc(3)) and returns a copy of
	’s1’ with the characters specified in ’set’ removed
	from the beginning and the end of the string.
-------------------------------------------------------------------------------
#include <stdio.h>

int main(void)
{
    // Test 1: Basic test with trimming spaces from the beginning and end
    char str1[] = "   Hello, World!   ";
    char set1[] = " ";
    char *trimmed1 = ft_strtrim(str1, set1);
    printf("Original: \"%s\"\n", str1);
    printf("Trimmed: \"%s\"\n", trimmed1);
    free(trimmed1);

    // Test 2: Test with a set of characters to be trimmed
    char str2[] = "---Trim Me!---";
    char set2[] = "-";
    char *trimmed2 = ft_strtrim(str2, set2);
    printf("Original: \"%s\"\n", str2);
    printf("Trimmed: \"%s\"\n", trimmed2);
    free(trimmed2);

    // Test 3: Test with an empty string
    char str3[] = "";
    char set3[] = " ";
    char *trimmed3 = ft_strtrim(str3, set3);
    printf("Original: \"%s\"\n", str3);
    printf("Trimmed: \"%s\"\n", trimmed3);
    free(trimmed3);

    // Test 4: Test with a string that doesn't need trimming
    char str4[] = "NoTrimsNeeded";
    char set4[] = " ";
    char *trimmed4 = ft_strtrim(str4, set4);
    printf("Original: \"%s\"\n", str4);
    printf("Trimmed: \"%s\"\n", trimmed4);
    free(trimmed4);

    return 0;
}
*/