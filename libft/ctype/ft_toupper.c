/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:04:23 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c -= 32;
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
#include <ctype.h> // For comparison with the standard toupper

int main() {
    // Test case 1: Converting a lowercase letter to uppercase
    char c1 = 'h';
    int result1_ft_toupper = ft_toupper(c1);
    int result1_toupper = toupper(c1);
    printf("Test case 1: ft_toupper('%c') = '%c', toupper('%c') =
		'%c'\n", c1, result1_ft_toupper, c1, result1_toupper);

    // Test case 2: Converting an uppercase letter (should remain unchanged)
    char c2 = 'K';
    int result2_ft_toupper = ft_toupper(c2);
    int result2_toupper = toupper(c2);
    printf("Test case 2: ft_toupper('%c') = '%c', toupper('%c') =
		'%c'\n", c2, result2_ft_toupper, c2, result2_toupper);

    // Test case 3: Converting a non-letter character (should remain unchanged)
    char c3 = '3';
    int result3_ft_toupper = ft_toupper(c3);
    int result3_toupper = toupper(c3);
    printf("Test case 3: ft_toupper('%c') = '%c', toupper('%c') =
		'%c'\n", c3, result3_ft_toupper, c3, result3_toupper);

    return 0;
}
*/