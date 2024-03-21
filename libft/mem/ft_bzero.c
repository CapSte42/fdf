/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:08:08 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*DESCRIPTION
      The  bzero()  function  erases the data in the n bytes of the memory
      starting at the location pointed to by s, by  writing  zeros  (bytes
      containing '\0') to that area.

  RETURN VALUE
      None.
-------------------------------------------------------------------------------
#include <stdio.h>

int main() 
{
    // Test case 1: Test with an array of integers
    int arr1[] = {1, 2, 3, 4, 5};
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("Before bzero:\n");
    for (size_t i = 0; i < size1; ++i) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    ft_bzero(arr1, size1 * sizeof(arr1[0]));

    printf("After bzero:\n");
    for (size_t i = 0; i < size1; ++i) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Test case 2: Test with a character array
    char str[] = "Hello, World!";
    size_t size2 = ft_strlen(str);

    printf("Before bzero: %s\n", str);

    ft_bzero(str, size2);

    printf("After bzero: %s\n", str);

    return 0;
}
*/