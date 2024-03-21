/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:51 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*DESCRIPTION
       The  strlen() function calculates the length of the string
       pointed to by  s,  excluding  the  terminating  null  byte
       ('\0').

RETURN VALUE
       The  strlen()  function returns the number of bytes in the
       string pointed to by s.
-------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h> // For comparison with the standard strlen

int main() {
    // Test case 1: Calculating the length of a string
    char str1[] = "Hello, World!";
    unsigned int result1 = ft_strlen(str1);
    printf("Test case 1: ft_strlen(\"%s\") = %u\n", str1, result1);

    // Test case 2: Calculating the length of an empty string
    char str2[] = "";
    unsigned int result2 = ft_strlen(str2);
    printf("Test case 2: ft_strlen(\"%s\") = %u\n", str2, result2);

    // Test case 3: Calculating the length of a string with spaces
    char str3[] = "   Spaces   ";
    unsigned int result3 = ft_strlen(str3);
    printf("Test case 3: ft_strlen(\"%s\") = %u\n", str3, result3);

    // Test case 4: Comparison with standard strlen
    char str4[] = "Comparison Test";

    // Using ft_strlen
    unsigned int result4 = ft_strlen(str4);
    printf("Test case 4 (ft_strlen): %u\n", result4);

    // Using standard strlen
    unsigned int result4_std = strlen(str4);
    printf("Test case 4 (strlen): %u\n", result4_std);

    return 0;
}
*/
