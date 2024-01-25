/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:10:00 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && (s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	if (i > 0 && i == n)
		i--;
	return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
}

/*DESCRIPTION
       The  strncmp() function compares the two strings
       s1 and s2.  The locale is not  taken  into  ac‐
       count  (for a locale-aware comparison, see str‐
       coll(3)).  It returns  an  integer  less  than,
       equal  to, or greater than zero if s1 is found,
       respectively, to be less than, to match, or  be
       greater than s2.

       The  strncmp()  function  is similar, except it
       compares only the first (at most) n bytes of s1
       and s2.

RETURN VALUE
       The  strcmp() and strncmp() functions return an
       integer less than, equal to,  or  greater  than
       zero  if  s1  (or the first n bytes thereof) is
       found, respectively, to be less than, to match,
       or be greater than s2.
-------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h> // For comparison with the standard strncmp

int main() {
    // Test case 1: Comparing two equal strings
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    size_t n1 = 0;
    int result1 = ft_strncmp(str1, str2, n1);
    printf("Test case 1: ft_strncmp(\"%s\", \"%s\", %zu) = 
	%d\n", str1, str2, n1, result1);

    // Test case 2: Comparing two different strings
    char str3[] = "Hello, World!";
    char str4[] = "Bonjour, World!";
    size_t n2 = 0;
    int result2 = ft_strncmp(str3, str4, n2);
    printf("Test case 2: ft_strncmp(\"%s\", \"%s\", %zu) = 
	%d\n", str3, str4, n2, result2);

    // Test case 3: Comparing two strings with limited length
    char str5[] = "Comparison Test";
    char str6[] = "Compressed Test";
    size_t n3 = 6;
    int result3 = ft_strncmp(str5, str6, n3);
    printf("Test case 3: ft_strncmp(\"%s\", \"%s\", %zu) = 
	%d\n", str5, str6, n3, result3);

    // Test case 4: Comparison with standard strncmp
    char str7[] = "Comparison Test";
    char str8[] = "Compressed Test";
    size_t n4 = 6;

    // Using ft_strncmp
    int result4 = ft_strncmp(str7, str8, n4);
    printf("Test case 4 (ft_strncmp): %d\n", result4);

    // Using standard strncmp
    int result4_std = strncmp(str7, str8, n4);
    printf("Test case 4 (strncmp): %d\n", result4_std);

    return 0;
}
*/