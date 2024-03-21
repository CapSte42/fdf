/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:17 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tot;
	void	*ptr;

	tot = nmemb * size;
	if (nmemb != 0 && tot / nmemb != size)
		return (NULL);
	ptr = malloc(tot);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, tot);
	return (ptr);
}

/*DESCRIPTION
       The  calloc() function allocates memory for an array of nmemb
       elements of size bytes each and returns a pointer to the  al‐
       located memory.  The memory is set to zero.  If nmemb or size
       is 0, then calloc() returns either NULL, or a unique  pointer
       value  that  can  later be successfully passed to free().  If
       the multiplication of nmemb and size would result in  integer
       overflow,  then  calloc()  returns an error.  By contrast, an
       integer overflow would not be detected in the following  call
       to  malloc(), with the result that an incorrectly sized block
       of memory would be allocated:

           malloc(nmemb * size);

	RETURN VALUE
       The  malloc()  and calloc() functions return a pointer to the
       allocated memory, which is suitably aligned for any  built-in
       type.   On error, these functions return NULL.  NULL may also
       be returned by a successful call to malloc() with a  size  of
       zero,  or by a successful call to calloc() with nmemb or size
       equal to zero.

    ERRORS
       calloc(), malloc(), realloc(), and  reallocarray()  can  fail
       with the following error:

       ENOMEM Out  of  memory.   Possibly,  the  application hit the
              RLIMIT_AS or  RLIMIT_DATA  limit  described  in  getr‐
              limit(2).   
-------------------------------------------------------------------------------
#include <stdio.h>

int main() {
    // Test case 1
    size_t nmemb1 = 5;
    size_t size1 = 4;
    int *arr1 = (int *)ft_calloc(nmemb1, size1);

    if (arr1 != NULL) {
        for (size_t i = 0; i < nmemb1; i++) {
            printf("%d ", arr1[i]);
        }
        printf("\n");
        free(arr1);
    } else {
        printf("Allocation failed for test case 1\n");
    }

    // Test case 2
    size_t nmemb2 = 0;
    size_t size2 = 4;
    int *arr2 = (int *)ft_calloc(nmemb2, size2);

    if (arr2 == NULL) {
        printf("Allocation failed for test case 2 as expected\n");
    } else {
        free(arr2);
    }

    return 0;
}*/