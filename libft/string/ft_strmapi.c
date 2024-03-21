/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:56 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*result;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*Parameters
	s: The string on which to iterate.
	f: The function to apply to each character.
Return value
	The string created from the successive applications
	of ’f’.
	Returns NULL if the allocation fails.
External functs
	malloc
Description
	Applies the function ’f’ to each character of the
	string ’s’, and passing its index as first argument
	to create a new string (with malloc(3)) resulting
	from successive applications of ’f’.
-------------------------------------------------------------------------------

#include <stdio.h>

char	st_toupper(unsigned int i, char c)
{
	if ('a' <= c && c <= 'z')
		c -= 32;
	return (c);
}

int main(void)
{
    // Test string
    const char *test_string = "Hello, World!";

    // Test ft_strmapi with direct use of ft_toupper
    char *result = ft_strmapi(test_string, &st_toupper);

    if (result)
    {
        printf("Original String: %s\n", test_string);
        printf("Uppercased String: %s\n", result);

        // Don't forget to free the allocated memory
        free(result);
    }
    else
    {
        printf("Memory allocation failed for ft_strmapi.\n");
    }

    return 0;
}
*/