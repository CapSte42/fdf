/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:07:50 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	void	*bellafra;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		bellafra = f(lst->content);
		new_elem = ft_lstnew(bellafra);
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			del(bellafra);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}
/*la variabile bellafra e' cosi' denominata in memoria del fu smontuor.*/
/*Parameters
	lst: The address of a pointer to a node.
	f: The address of the function used to iterate on
	the list.
	del: The address of the function used to delete
	the content of a node if needed.
Return value
	The new list.
	NULL if the allocation fails.
External functs
	malloc, free
Description
	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node. Creates a new
	list resulting of the successive applications of
	the function ’f’. The ’del’ function is used to
	delete the content of a node if needed.*/