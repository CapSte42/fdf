/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:28 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	if (str == NULL)
		return (NULL);
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*DESCRIPTION
       The strdup() function returns a pointer to a new string which is a
       duplicate of the string s.  Memory for the new string is  obtained
       with malloc(3), and can be freed with free(3).

RETURN VALUE
       On success, the strdup() function returns a pointer to the  dupli‐
       cated  string.   It returns NULL if insufficient memory was avail‐
       able, with errno set to indicate the cause of the error.

ERRORS
       ENOMEM Insufficient memory available to allocate duplicate string.
-------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h> // For comparison with the standard strdup

int main() {
    // Test case 1: Duplicating a string
    char str1[] = "Hello, World!";
    char *duplicate1 = ft_strdup(str1);
    printf("Test case 1: ft_strdup(\"%s\") = \"%s\"\n", str1, duplicate1);
    free(duplicate1);

    // Test case 2: Duplicating an empty string
    char str2[] = "";
    char *duplicate2 = ft_strdup(str2);
    printf("Test case 2: ft_strdup(\"%s\") = \"%s\"\n", str2, duplicate2);
    free(duplicate2);

    // Test case 3: Duplicating a string with spaces
    char str3[] = "   Spaces   ";
    char *duplicate3 = ft_strdup(str3);
    printf("Test case 3: ft_strdup(\"%s\") = \"%s\"\n", str3, duplicate3);
    free(duplicate3);

    // Test case 4: Comparison with standard strdup
    char str4[] = "Comparison Test";

    // Using ft_strdup
    char *duplicate4 = ft_strdup(str4);
    printf("Test case 4 (ft_strdup): \"%s\"\n", duplicate4);
    free(duplicate4);

    // Using standard strdup
    char *duplicate4_std = strdup(str4);
    printf("Test case 4 (strdup): \"%s\"\n", duplicate4_std);
    free(duplicate4_std);

    return 0;
}
*/