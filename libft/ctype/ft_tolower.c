/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:04:17 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += 32;
	return (c);
}

/*DESCRIPTION
       These functions convert lowercase letters to uppercase, and vice versa.

       If  c is a lowercase letter, toupper() returns its uppercase equivalent,
	   if an uppercase representation exists in the current locale.  Otherwise,
	   it returns  c.
	   The  toupper_l()  function performs the same task, but uses the locale
	   referred to by the locale handle locale.

       If  c is an uppercase letter, tolower() returns its lowercase equivalent
	   , if a lowercase representation exists in the current locale.  Otherwise
	   it returns  c.   The  tolower_l()  function performs the same task, but 
	   uses the locale referred to by the locale handle locale.

       If c is neither an unsigned char value nor EOF, the behavior of these 
	   functions is undefined.

       The behavior of toupper_l() and tolower_l() is undefined if locale is the
		special locale object LC_GLOBAL_LOCALE (see duplocale(3)) or is not a 
		valid locale object handle.

RETURN VALUE
       The value returned is that of the converted letter, or c if the 
	   conversion was not possible.
-------------------------------------------------------------------------------
#include <stdio.h>
#include <ctype.h> // For comparison with the standard tolower and toupper

int main() {
    // Test case 1: Converting an uppercase letter to lowercase
    char c1 = 'H';
    int result1_ft_tolower = ft_tolower(c1);
    int result1_tolower = tolower(c1);
    printf("Test case 1: ft_tolower('%c') = '%c', tolower('%c') =
		'%c'\n", c1, result1_ft_tolower, c1, result1_tolower);

    // Test case 2: Converting a non-letter character
    char c3 = '5';
    int result3_ft_tolower = ft_tolower(c3);
    int result3_tolower = tolower(c3);
    printf("Test case 2: ft_tolower('%c') = '%c', tolower('%c') =
		'%c','\n", c3, result3_ft_tolower, c3, result3_tolower,);

    return 0;
}
*/